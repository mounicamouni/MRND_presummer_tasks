from bs4 import BeautifulSoup
import openpyxl
import requests



wb1 = openpyxl.Workbook()
sheet1 = wb1.get_sheet_by_name('Sheet')
wb1.remove_sheet(sheet1)
sheet1=wb1.create_sheet(title='mockresult')
'''
url = "https://d1b10bmlvqabco.cloudfront.net/attach/inpg92dp42z2zo/hdff4poirlh7i6/io5hun2sdr21/mock_results.html"

r  = requests.get(url)
data = r.text

soup = BeautifulSoup(data,'html.parser')
'''

soup = BeautifulSoup(open('mockresult.html'))

print(soup.title)
x=soup.find_all('th')
for i in x[1:]:
    print(i.get_text())

y=soup.find_all('tr')
print(y)
for i in y[:]:
    x=i.get_text().strip()
    print(x.len())
    print(i.get_text())


wb1.save('soup.xlsx')
