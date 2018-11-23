import sys
sys.stdout = open("vstupy","w")
for i in range(13):
    for j in range(60):
        for k in range(2):
            for l in range(20):
                print(":".join(map(str,[i,j])))
                print(":".join(map(str,[k,l])))
                print()
