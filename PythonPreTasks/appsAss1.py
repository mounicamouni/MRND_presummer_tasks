import click
'''
@click.command()
@click.option('--count', default=1, help='Number of greetings.')
@click.option('--name', prompt='Your name',
              help='The person to greet.')
def hello(count, name):
    """Simple program that greets NAME for a total of COUNT times."""
    for x in range(count):
        click.echo('Hello %s!' % name)

@click.command()
@click.option('--count', default=1, help='number of greetings')
@click.option('--name',default="mouni")
@click.argument('d',":",default=":")
def hello(count, name,d):
    click.echo(d)
    for x in range(count):
        click.echo('Hello %s!' % name)

@click.command()
@click.option("-x",nargs=2)
@click.argument('src',nargs=-1)
@click.argument('des',nargs =1)
def hello(x,src,des):
    for i in x:
        click.echo(i)
    click.echo("source....")
    for i in src :
        click.echo(i)
    click.echo("desss")
    for i in des:
        click.echo(i)
'''
import string
@click.command()
@click.option('--removedigits/--no-removedigits', default=False,help="Removes the numbers")
@click.argument('func',nargs=1)
@click.option('-d',default=':' ,nargs=1,help="--delimiter TEXT default value is :")
@click.argument('src',nargs=-1)
def info(removedigits,func,d,src):
    '''
    click.echo(removedigits)
    click.echo(func)
    click.echo(d)
    for i in src:
        click.echo(i)
    click.echo("delimiter is %s" %d)'''
    res=""
    if func=='concat':
        res=d.join(src)
    if func=='upper':
        for i in src:
            res+=i
        res=res.upper()
    if func=='lower':
        for i in src:
            res+=i
        res=res.lower()
    if removedigits:
        r=""
        for i in res:
            if i not in string.digits:
                r+=i
        res=r
    click.echo(res)
if __name__ == '__main__':
    info()