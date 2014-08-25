import random
n = random.randint(1, 100000)
m = random.randint(1, 100000)
f = open("in", 'w')
f.write("%d %d\n" % (n, m))

for i in range(n+m):
    x = random.randrange(1, 1440)
    y = random.randint(0, 100)
    f.write("%d %d\n" % (x, y))
