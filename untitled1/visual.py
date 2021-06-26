import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import re
import os
from PIL import Image
from pyecharts.charts import Pie
from pyecharts import options as opts

pd.set_option("display.max_column",None)


#常规赛数据
df_season = pd.read_csv("/home/kesci/input/qiao2420/playoff.csv")
df_season.rename(columns={"出手":"总出手","命中":"总命中","命中.1":"三分命中","出手.1":"三分出手","命中.2":"罚球命中","出手.2":"罚球出手"},
                inplace=True)
df_season.head()

#单场比赛各得分占比
interval = ["20分及以下","20-30","30-40","40-50","大于50"]
value = pd.cut(df_season["得分"],bins=[0,20,30,40,50,100],labels=interval).value_counts(normalize=True)[interval].values

pie = (
    Pie()
    .add(
        "",
        [list(z) for z in zip(interval, value)],
        center=["50%", "50%"],
       # radius=["50%","75%"]
    )
    .set_global_opts(
        title_opts=opts.TitleOpts(title="单场比赛各个得分段占比",pos_left="center"),
        legend_opts=opts.LegendOpts(
                is_show=False
            )
    )
    .set_series_opts(label_opts=opts.LabelOpts(formatter="{b}: {d}%")))

pie.render_notebook()

#乔丹进攻偏好
df_season["两分出手"] = df_season["总出手"]-df_season["三分出手"]

two_point_select= df_season["两分出手"].sum()/df_season["总出手"].sum()
three_point_select = 1-two_point_select
two_point_ratio = (df_season["得分"]-df_season["三分命中"]*3-df_season["罚球命中"]).sum()/df_season["得分"].sum()
free_throw_ratio = df_season["罚球命中"].sum()/df_season["得分"].sum()
three_point_ratio = 1-two_point_ratio-free_throw_ratio

pie = (
    Pie()
        .add(
        "",
        [("两分球", two_point_ratio), ("三分球", three_point_ratio), ("罚球", free_throw_ratio)],
        # [list(z) for z in zip(education.index, np.round(education.values,4))],
        center=["33%", "50%"],
        radius=["50%", "75%"]
    )
        .add(
        "",
        [("两分出手", two_point_select), ("三分出手", three_point_select)],
        # [list(z) for z in zip(education.index, np.round(education.values,4))],
        center=["78%", "50%"],
        radius=["50%", "75%"]
    )
        .set_global_opts(
        title_opts=opts.TitleOpts(title="得分来源占比（左）和出手选择占比（右）", pos_left="35%"),
        legend_opts=opts.LegendOpts(
            is_show=False
        )

    )

        .set_series_opts(label_opts=opts.LabelOpts(formatter="{b}: {d}%")))

pie.render_notebook()

#生涯对战
pattern = re.compile(r'[\u4E00-\u9FA5]+')
df_season["team_list"] = df_season["比赛"].str.findall(pattern).map(set)

def get_opp(x,num=0):
    period_dict = {0:"公牛",1:"奇才"}
    opp = (x-set([period_dict[num]])).pop()
    if opp == "人":
        return "76人"
    elif opp == "凯尔特":
        return "凯尔特人"
    elif opp == "超音速":
        return "雷霆"
    elif opp == "子弹":
        return "奇才"
    else:
        return opp
df_season.loc[~df_season["赛季"].isin(["01-02","02-03"]),"opp"] = df_season["team_list"].map(lambda x : get_opp(x,0))
df_season.loc[df_season["赛季"].isin(["01-02","02-03"]),"opp"] = df_season["team_list"].map(lambda x : get_opp(x,1))

fig, ax = plt.subplots(figsize=(12,8))
order = df_season.groupby("opp")["得分"].mean().sort_values(ascending=False).index
sns.barplot(y="opp",x = "得分",order=order,data=df_season,color='#3c7f99',ci=None)
plt.box(False)
fig.text(x=0.02, y=0.90, s='对阵联盟各个球队的场均得分',
         fontsize=32, weight='bold', color='white', backgroundcolor='#c5b783')
plt.tick_params(axis='both', which='major', labelsize=16)
ax.xaxis.grid(which='both', linewidth=0.5, color='#3c7f99')
plt.xlabel('')
plt.ylabel('')

#常规赛胜负
pattern = re.compile("(\d+)-(\d+)")
df_season["diff"] = df_season["比赛"].str.findall(pattern).map(lambda x : np.abs(int(x[0][0])-int(x[0][1])))

fig, ax = plt.subplots(figsize=(12,8))
sns.swarmplot(x="果",y="diff",data=df_season)
fig.text(x=0.1, y=0.90, s='输赢时的分差',
         fontsize=32, weight='bold', color='white', backgroundcolor='#3c7f99')
plt.tick_params(axis='both', which='major', labelsize=16)
plt.xlabel("分差",fontsize=16)
plt.ylabel("比赛结果",fontsize=16)

#季后赛各轮输赢分差
df_playoff = pd.read_csv("/home/kesci/input/qiao2420/playoff.csv")
pattern = re.compile("(\d+)-(\d+)")

df_playoff["diff"] = df_playoff["比赛"].str.findall(pattern).map(lambda x : np.abs(int(x[0][0])-int(x[0][1])))

color = df_playoff["果"].map({"胜":"#e60000","负":"#73e68c"})

fig, ax = plt.subplots(figsize=(12, 8))
fig.text(x=0.03, y=0.92, s='季后赛各轮次的输赢分差', fontsize=32,
         weight='bold', color='white', backgroundcolor='#3c7f99')
plt.yticks([1,2,3,4],labels=["第一轮","第二轮","分区决赛","总决赛"])
plt.scatter(df_playoff["diff"], df_playoff["轮次"], alpha=0.35,c=color,s=500)
plt.scatter(df_playoff["diff"], df_playoff["轮次"], c=color)
plt.tick_params(axis='both', which='both', length=0)
plt.tick_params(axis='both', which='major', labelsize=16)
ax.xaxis.grid(which='both', linewidth=0.75)
#plt.xticks(np.arange(0,61,10), [str(i)+"k" for i in range(0,61,10)])
plt.xlabel('分差', fontsize=18)
plt.box(False)
#seed_scale_plot()