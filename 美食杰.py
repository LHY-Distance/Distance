
from bs4 import BeautifulSoup           # 网页解析，获取数据（爬到网页上，把数据进行一个拆分）
import re                               # 正则表达式，进行文字匹配（进行数据的提炼）
import urllib.request
import urllib.error                     # 制定URL，获取网页数据
import xlwt                             # 进行excel操作

def main():
    baseurl="https://www.meishij.net/chufang/diy/?&page="
    # 一个功能就是一个函数，方便后续的调用
    # 1.爬取网页
    datalist = getData(baseurl)
    savepath = ".\\美食杰.xls"
    # 2.逐一解析数据
    # 3.保存数据
    saveData(datalist,savepath)


# 详情链接
findlink = re.compile(r'<a.*? href="(.*?)".*?>', re.S)          #创建正则表达式对象，表示规则（字符串的模式）

# 食物图片
findImgsrc = re.compile(r'<img.*src="(.*?)".*?', re.S)          #re.S 让换行符包含在字符中


# 1.爬取网页
def getData(baseurl):
    datalist = []
    for i in range(0,10):               # 调用获取页面信息的函数，10次
        url = baseurl + str(i)
        html = askURL(url)              # 保存获取到的网页源码

        # 2.逐一解析数据（要在for循环里面）
        soup = BeautifulSoup(html,"html.parser")
        for item in soup.find_all('div',class_="listtyle1"):        # 查找符合要求的字符串，形成列表
            data = []                                               # 保存一道菜的所有信息
            item = str(item)

            # 影片详情的链接
            if re.findall(findlink, item):
                link = re.findall(findlink,item)[0]             # re库用来通过正则表达式查找指定的字符串
                get_detail(link, data)                          # 写一个新的函数 对链接发起请求
                data.append(link)                               # 添加链接

            if re.findall(findImgsrc,item):
                imgSrc=re.findall(findImgsrc,item)[0]
                data.append(imgSrc)                             # 添加图片

            datalist.append(data)                               # 把处理好的信息放入datalist中
    print(datalist)
    return datalist



# 爬取详情页（对详情页的url发起请求并获取信息）
def get_detail(link, data):                                             # 传入两个参数，第一个是url，第二个是列表
    html = askURL(link)                                                 # 发起请求，拿到响应
    soup = BeautifulSoup(html, "html.parser")                           # 拿到的源代码进行Beautiful soup处理
    title = ''                                                          # 初始化
    if soup.select_one("h1.title a") is not None:
        title = soup.select_one("h1.title a").text                      # 获取标题，用text 只获取文字内容
    data.append(title)                                                  # 将标题添加到列表里
    details = soup.select("div.editnew.edit>div.content.clearfix p")    # 拿到所有段落，得到列表  注意：select拿到的是列表，select_one拿到的是单独的（我不知道怎么描述反正不是列表）
    content = ''                                                        # 初始化
    pictures = []                                                       # 初始化
    for d in details:                                                   # 循环列表
        content += d.text.strip()                                       # text获取文字内容（.text只能对单独的元素进行文字提取处理，列表不行）
        if d.select_one("img") is not None:
            pictures.append(d.select_one("img")['src'])                 # 获取详情页的图片（d.select_one("img")['src']这样是拿到img标签的src属性的意思）
    data.append(content)                                                # 将内容加入到列表里面
    data.append(pictures)                                               # 将图片添加到列表里
    return data                                                         # 返回列表

# 得到指定一个URL的网页内容
def askURL(url):
    head={"User-Agent":"Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/86.0.4240.198 Safari/537.36"}
    # head 是模拟浏览器头部信息，向服务器发送消息
    # {}里的内容为用户代理，表示告诉服务器，我们是什么类型的机器、浏览器（本质上是告诉浏览器，我们可以接收什么水平的文件内容）
    request = urllib.request.Request(url, headers=head)
    html = ""                                                           # 初始化
    try:
        response = urllib.request.urlopen(request)
        html = response.read().decode("utf-8")
        #print(html)
    except urllib.error.URLError as e:
        if hasattr(e,"code"):
            print(e.code)
        if hasattr(e,"reason"):
            print(e.reason)
    return html

# # 3.保存数据
def saveData(datalist,savepath):
    print("save..")
    workbook = xlwt.Workbook(encoding="utf-8")                          # 创建workbook对象
    worksheet=workbook.add_sheet('美食杰',cell_overwrite_ok=True)        # 创建工作表
    col=("菜名","做法","步骤图片","封面图片")
    for i in range(0,4):
        worksheet.write(0,i,col[i])                                     # 列名，第一个参数是行，第二个参数是列，第三个参数是内容
    for i in range(0,180):
        print("第%d条"%i)
        data=datalist[i]
        for j in range(0,4):
            worksheet.write(i+1,j,data[j])                              # 数据，第一个参数是行，第二个参数是列，第三个参数是内容
    workbook.save('美食杰.xls')                                          # 保存为excel表

    with open('美食杰.txt', 'w', encoding='utf-8') as f:                 # 存为txt文件
        f.write('美食杰食谱：\n')
        for data in datalist:
            f.write("菜名：" + data[0] + "\n")
            f.write("做法：" + data[1] + "\n")
            f.write("步骤图片：" + str(data[2]) + "\n")
            f.write("封面图片：" + data[3] + "\n")
            f.write("\n\n")
    f.close()

main()
print("爬取完毕")


