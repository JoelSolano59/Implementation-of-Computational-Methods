def setXY(x, y):
    xyset = set()
    for i in x:
        for j in y:
            xyset.add(i+j)
    print(xyset)
    return

def closureX(x):
    xset = set()
    for i in x:
        for j in x:
            for k in x:
                xset.add(i+j+k)
    print(xset)
    return

def closureY(y):
    yset = set()
    for i in y:
        for j in y:
            if len(i+j) <= 3:
                yset.add(i+j)
    print(yset)
    return

def closureXY(x, y):
    xset = set()
    yset = set()
    xyset = set()
    for i in x:
        for j in x:
            for k in x:
                xset.add(i+j+k)
    for k in y:
        for l in y:
            yset.add(k+l)
    for m in xset:
        for n in yset:
            if len(m+n) <= 4:
                xyset.add(m+n)
    print(xyset)
    return

def main():
    x = ['aa','bb']
    y = ['b','ab']

    setXY(x, y)
    closureX(x)
    closureY(y)
    closureXY(x, y)

    return

main()