import re
with open("types.txt") as fi:
    for l in fi:
        d =l.strip()
        d2 = re.sub("[^A-Za-z]","_",d)
        print("autotype({},debug_{})".format(d,d2))
