import xlrd
import pymysql

# 打开数据所在的工作簿，以及选择存有数据的工作表

book = xlrd.open_workbook('playoff.xls')


conn = pymysql.connect(
    host='localhost',
    user='root',
    passwd='123456',
    db='keshe',
    port=3306,
    charset='utf8'
)
sheet = book.sheet_by_name("Sheet1")
# 获得游标
cur = conn.cursor()
# 创建插入SQL语句

query = 'insert into sheet1 (ID, SNAME, SSEASON, ROUND, SMATCH, TEAM) values (%s, %s, %s,%s, %s, %s)'

for r in range(1, sheet.nrows):
    ID = sheet.cell(r, 0).value
    SNAME = sheet.cell(r, 1).value
    SSEASON = sheet.cell(r, 2).value
    ROUND = sheet.cell(r, 3).value
    SMATCH = sheet.cell(r, 4).value
    TEAM = sheet.cell(r, 5).value
    values = (ID, SNAME, SSEASON, ROUND, SMATCH, TEAM)
    cur.execute(query, values)
    conn.commit()

conn.close()
columns = str(sheet.ncols)
rows = str(sheet.nrows)
print("导入 " + columns + " 列 " + rows + " 行数据到MySQL数据库!")


sheet = book.sheet_by_name("Sheet2")
# 获得游标
cur = conn.cursor()
# 创建插入SQL语句

query = 'insert into sheet2 (SSEASON, SMATCH, SRATE, SNUMBER, STAKEN) values (%s, %s, %s,%s, %s)'

for r in range(1, sheet.nrows):
    SSEASON = sheet.cell(r, 0).value
    SMATCH = sheet.cell(r, 1).value
    SRATE = sheet.cell(r, 2).value
    SNUMBER = sheet.cell(r, 3).value
    STAKEN = sheet.cell(r, 4).value
    values = (SSEASON, SMATCH, SRATE, SNUMBER, STAKEN)
    cur.execute(query, values)
    conn.commit()

conn.close()
columns = str(sheet.ncols)
rows = str(sheet.nrows)
print("导入 " + columns + " 列 " + rows + " 行数据到MySQL数据库!")

sheet = book.sheet_by_name("Sheet3")
# 获得游标
cur = conn.cursor()
# 创建插入SQL语句

query = 'insert into sheet3 (SSEASON, SMATCH, TRATE, TNUMBER, TTAKEN) values (%s, %s, %s,%s, %s)'

for r in range(1, sheet.nrows):
    SSEASON = sheet.cell(r, 0).value
    SMATCH = sheet.cell(r, 1).value
    TRATE = sheet.cell(r, 2).value
    TNUMBER = sheet.cell(r, 3).value
    TTAKEN = sheet.cell(r, 4).value
    values = (SSEASON, SMATCH, TRATE, TNUMBER, TTAKEN)
    cur.execute(query, values)
    conn.commit()

conn.close()
columns = str(sheet.ncols)
rows = str(sheet.nrows)
print("导入 " + columns + " 列 " + rows + " 行数据到MySQL数据库!")

sheet = book.sheet_by_name("Sheet4")
# 获得游标
cur = conn.cursor()
# 创建插入SQL语句

query = 'insert into sheet4 (SSEASON, SMATCH, PRATE, PNUMBER, PTAKEN) values (%s, %s, %s,%s, %s)'

for r in range(1, sheet.nrows):
    SSEASON = sheet.cell(r, 0).value
    SMATCH = sheet.cell(r, 1).value
    PRATE = sheet.cell(r, 2).value
    PNUMBER = sheet.cell(r, 3).value
    PTAKEN = sheet.cell(r, 4).value
    values = (SSEASON, SMATCH, PRATE, PNUMBER, PTAKEN)
    cur.execute(query, values)
    conn.commit()

conn.close()
columns = str(sheet.ncols)
rows = str(sheet.nrows)
print("导入 " + columns + " 列 " + rows + " 行数据到MySQL数据库!")

sheet = book.sheet_by_name("Sheet5")
获得游标
cur = conn.cursor()
创建插入SQL语句

query = 'insert into sheet5 (SSEASON, SMATCH, BACKBOARD, FROUNTC, BACKC) values (%s, %s, %s,%s, %s)'

for r in range(1, sheet.nrows):
    SSEASON = sheet.cell(r, 0).value
    SMATCH = sheet.cell(r, 1).value
    BACKBOARD = sheet.cell(r, 2).value
    FROUNTC = sheet.cell(r, 3).value
    BACKC = sheet.cell(r, 4).value
    values = (SSEASON, SMATCH, BACKBOARD, FROUNTC, BACKC)
    cur.execute(query, values)
    conn.commit()

conn.close()
columns = str(sheet.ncols)
rows = str(sheet.nrows)
print("导入 " + columns + " 列 " + rows + " 行数据到MySQL数据库!")


sheet = book.sheet_by_name("Sheet6")
# 获得游标
cur = conn.cursor()
# 创建插入SQL语句

query = 'insert into sheet6 (SSEASON, RESULT, SMATCH, SATTACK, ST, BLOCKSHOT, FAULT, FOUL, SCORE) values (%s, %s, %s,%s, %s, %s, %s,%s, %s)'

for r in range(1, sheet.nrows):
    SSEASON = sheet.cell(r, 0).value
    RESULT = sheet.cell(r, 1).value
    SMATCH = sheet.cell(r, 2).value
    SATTACK = sheet.cell(r, 3).value
    ST = sheet.cell(r, 4).value
    BLOCKSHOT = sheet.cell(r, 5).value
    FAULT = sheet.cell(r, 6).value
    FOUL = sheet.cell(r, 7).value
    SCORE = sheet.cell(r, 8).value
    values = (SSEASON, RESULT, SMATCH, SATTACK, ST, BLOCKSHOT, FAULT, FOUL,SCORE)
    cur.execute(query, values)
    conn.commit()

conn.close()
columns = str(sheet.ncols)
rows = str(sheet.nrows)
print("导入 " + columns + " 列 " + rows + " 行数据到MySQL数据库!")