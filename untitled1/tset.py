import pymysql
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import re
import os
from PIL import Image
from pyecharts.charts import Pie
from pyecharts import options as opts
import random
# %matplotlib


db = pymysql.connect(
    host='localhost',
    user='root',
    passwd='123456',
    db='keshe',
    port=3306,
    charset='utf8')

cursor = db.cursor()#获取一个游标
cursor.execute('select ID, SNAME, SSEASON, ROUND, SMATCH, TEAM from sheet1');
rows = cursor.fetchall()
df_season0 = pd.DataFrame([[j for j in i] for i in rows])
df_season0.rename(columns={0:'比赛编号', 1:'球员', 2:'赛季', 3:'轮次', 4:'比赛', 5:'所在球队'}, inplace=True)
print(df_season0.head())

cursor = db.cursor()#获取一个游标
cursor.execute('select  SSEASON, SMATCH, SRATE, SNUMBER, STAKEN from sheet2');
rows = cursor.fetchall()
df_season1 = pd.DataFrame([[ij for ij in i] for i in rows])
df_season1.rename(columns={0:'赛季', 1:'比赛', 2:'投篮命中率', 3:'投篮命中次数', 4:'投篮出手次数'}, inplace=True)
print(df_season1.head())

cursor = db.cursor()#获取一个游标
cursor.execute('select  SSEASON, SMATCH, TRATE, TNUMBER, TTAKEN from sheet3');
rows = cursor.fetchall()
df_season2 = pd.DataFrame([[ij for ij in i] for i in rows])
df_season2.rename(columns={0:'赛季', 1:'比赛', 2:'三分命中率', 3:'三分命中次数', 4:'三分出手次数'}, inplace=True)
print(df_season2.head())

cursor = db.cursor()#获取一个游标
cursor.execute('select  SSEASON, SMATCH, PRATE, PNUMBER, PTAKEN from sheet4');
rows = cursor.fetchall()
df_season3 = pd.DataFrame([[ij for ij in i] for i in rows])
df_season3.rename(columns={0:'赛季', 1:'比赛', 2:'罚球命中率', 3:'罚球命中次数', 4:'罚球出手次数'}, inplace=True)
print(df_season3.head())

cursor = db.cursor()#获取一个游标
cursor.execute('select  SSEASON, SMATCH, BACKBOARD, FROUNTC, BACKC from sheet5');
rows = cursor.fetchall()
df_season4 = pd.DataFrame([[ij for ij in i] for i in rows])
df_season4.rename(columns={0:'赛季', 1:'比赛', 2:'篮板', 3:'前场', 4:'后场'}, inplace=True)
print(df_season4.head())

cursor = db.cursor()#获取一个游标
cursor.execute('select  SSEASON, RESULT, SMATCH, SATTACK, ST, BLOCKSHOT, FAULT, FOUL, SCORE from sheet6');
rows = cursor.fetchall()
df_season5 = pd.DataFrame([[ij for ij in i] for i in rows])
df_season5.rename(columns={0:'赛季', 1:'结果', 2:'比赛', 3:'助攻', 4:'抢断', 5:'盖帽', 6:'失误', 7:'犯规', 8:'得分'}, inplace=True)
print(df_season5.head())

df=df_season0.merge(df_season1)
df1=df.merge(df_season2)
cols_to_use = df_season2.columns.difference(df.columns)
df2=pd.merge(df, df_season2[cols_to_use], left_index=True, right_index=True)
#print(df2.head())

cols_to_use = df_season3.columns.difference(df2.columns)
df3=pd.merge(df2, df_season3[cols_to_use], left_index=True, right_index=True)
#print(df3.head())

cols_to_use = df_season4.columns.difference(df3.columns)
df4=pd.merge(df3, df_season4[cols_to_use], left_index=True, right_index=True)
#print(df4.head())

cols_to_use = df_season5.columns.difference(df4.columns)
df5=pd.merge(df4, df_season5[cols_to_use], left_index=True, right_index=True)
print(df5)

