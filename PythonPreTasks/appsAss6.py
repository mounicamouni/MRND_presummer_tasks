import smtplib
import MySQLdb
import click
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText

@click.command()
@click.option("--reciever",prompt="enter the reciever mail id")
@click.option("--sender",prompt="enter your mail id")
@click.option("--pwd",prompt="enter your password")
@click.option("--colname",prompt="enter the college name")
def sedingMail(reciever,sender,pwd,colname):
    server = smtplib.SMTP('smtp.gmail.com',587)
    server.starttls()
    server.login("rndtestrnd123@gmail.com", "mrndmrnd")
    #server.login(sender,pwd)
    message="hello"

    msg = MIMEMultipart()  # create a message

    msg['From'] = sender
    msg['To'] = reciever
    msg['Subject'] = "This is TEST"
    msg.attach(MIMEText(message, 'plain'))

    conn = MySQLdb.connect('localhost', 'root', 'root', '')
    cur = conn.cursor()
    cur.execute('use mrnd')

    text = "Hi!\nHow are you?\nHere is the link you wanted:\nhttp://www.mouni"
    html = """\
    <html>
      <head></head>
      <body>
      <h2 style="text-align:center">College Report</h2>
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
    html+=""" </table>
     <h2>College Summary</h2>
     <table style="width:100%; text-align: left">
     <tr> <th>No.of students</th> <th>min score</th>
            <th> max score </th> <th> avg score </th> </tr>"""
    query="select count(*),min(m.total),max(m.total),avg(m.total) from marks m inner join students s on s.dbname=m.dbname where s.college ='{0}'".format(colname)
    cur.execute(query)
    for i in cur.fetchall():
            html+=""" <tr> """
            for x in i:
                    html+="""<td>  %s </td> """%x
                    #print(x)
            html+="""</tr>"""

    html+= """</table>
    </body>
    </html>
    """
    part1 = MIMEText(text, 'plain')
    part2 = MIMEText(html, 'html')

    msg.attach(part1)
    msg.attach(part2)

    server.send_message(msg)
    del msg

#
# @click.command()
# @click.option("--reciever",prompt="enter the reciever mail id")
# def sedingMail(reciever):
#     server = smtplib.SMTP('smtp.gmail.com',587)
#     server.starttls()
#     server.login("rndtestrnd123@gmail.com", "mrndmrnd")
#
#     message="hello"
#
#     msg = MIMEMultipart()  # create a message
#
#     msg['From'] = "rndtestrnd123@gmail.com"
#     msg['To'] = reciever
#     msg['Subject'] = "AmazonClone"
#     msg.attach(MIMEText(message, 'plain'))
#
#     server.send_message(msg)
#     del msg
# if __name__ == '__main__':
#     sedingMail()