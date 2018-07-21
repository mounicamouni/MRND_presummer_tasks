import smtplib
import MySQLdb
import click
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
#import socket
#socket.getaddrinfo('127.0.0.1', 8080)
server = smtplib.SMTP('smtp.gmail.com',587)
server.starttls()
server.login("rndtestrnd123@gmail.com", "mrndmrnd")

message="hello"
#server.sendmail("rndtestrnd123@gmail.com",'mounica2798@gmail.com',message)

msg = MIMEMultipart()  # create a message

msg['From'] = "rndtestrnd123@gmail.com"
msg['To'] = "mounica2798@gmail.com"
msg['Subject'] = "This is TEST"
msg.attach(MIMEText(message, 'plain'))

conn = MySQLdb.connect('localhost', 'root', 'root', '')
cur = conn.cursor()
cur.execute('use mrnd')

text = "Hi!\nHow are you?\nHere is the link you wanted:\nhttp://www.mouni"
colname="anits"
html = """\
<html>
  <head></head>
  <body>
    <p> from  %s college  </p>"""%colname
html+="""<table style="width:100%; text-align: left"> <tr> <th>name</th> <th>transform</th> 
        <th> custom </th> <th> piglatin </th> <th> topchars </th>
         <th> total </th>
         </tr>"""
query="select name,transform,custom,piglatin,topchars,total from marks m inner join students s on s.dbname=m.dbname where s.college ='{0}'".format(colname)
cur.execute(query)

for i in cur.fetchall():
        html+=""" <tr> """
        for x in i:
                html+="""<td>  %s </td> """%x
                #print(x)
        html+="""</tr>"""
html+=""" </table> </body>
</html>
"""

part1 = MIMEText(text, 'plain')
part2 = MIMEText(html, 'html')

msg.attach(part1)
msg.attach(part2)

# send the message via the server set up earlier.
server.send_message(msg)

del msg
#the above two lines or this
#text = msg.as_string()
#server.sendmail("rndtestrnd123@gmail.com",'mounica2798@gmail.com', text)
#server.quit()