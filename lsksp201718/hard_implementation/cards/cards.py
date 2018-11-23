mapa = {}

mapa["hearts"] = []
mapa["hearts"].append("     ")
mapa["hearts"].append(" # # ")
mapa["hearts"].append("#####")
mapa["hearts"].append(" ### ")
mapa["hearts"].append("  #  ")

mapa["clubs"] = []
mapa["clubs"].append(" ### ")
mapa["clubs"].append("  #  ")
mapa["clubs"].append("#####")
mapa["clubs"].append("# # #")
mapa["clubs"].append("  #  ")

mapa["diamonds"] = []
mapa["diamonds"].append("  #  ")
mapa["diamonds"].append(" ### ")
mapa["diamonds"].append("#####")
mapa["diamonds"].append(" ### ")
mapa["diamonds"].append("  #  ")

mapa["spades"] = []
mapa["spades"].append("  #  ")
mapa["spades"].append(" ### ")
mapa["spades"].append("#####")
mapa["spades"].append("# # #")
mapa["spades"].append("  #  ")

card = []
card.append("+-----------------------+")
card.append("|{}                   {}|")
card.append("|                       |")
card.append("| {}   {}   {} |")
card.append("| {}   {}   {} |")
card.append("| {}   {}   {} |")
card.append("| {}   {}   {} |")
card.append("| {}   {}   {} |")
card.append("|                       |")
card.append("| {}   {}   {} |")
card.append("| {}   {}   {} |")
card.append("| {}   {}   {} |")
card.append("| {}   {}   {} |")
card.append("| {}   {}   {} |")
card.append("|                       |")
card.append("| {}   {}   {} |")
card.append("| {}   {}   {} |")
card.append("| {}   {}   {} |")
card.append("| {}   {}   {} |")
card.append("| {}   {}   {} |")
card.append("|                       |")
card.append("| {}   {}   {} |")
card.append("| {}   {}   {} |")
card.append("| {}   {}   {} |")
card.append("| {}   {}   {} |")
card.append("| {}   {}   {} |")
card.append("|                       |")
card.append("|                       |")
card.append("|{}                   {}|")
card.append("+-----------------------+")

vstup = input().split()
if vstup[1]=="king" or vstup[1]=="ace" or vstup[1]=="queen" or vstup[1]=="jack":
    count = 1
elif vstup[1]=="two":
    count = 2
elif vstup[1]=="three":
    count = 3
elif vstup[1]=="four":
    count = 4
elif vstup[1]=="five":
    count = 5
elif vstup[1]=="six":
    count = 6
elif vstup[1]=="seven":
    count = 7
elif vstup[1]=="eight":
    count = 8
elif vstup[1]=="nine":
    count = 9
elif vstup[1]=="ten":
    count = 10
number = count

if number ==10:
    sign = str(count)
elif number != 1:
    sign = str(count)
else:
    sign = vstup[1][0].upper()

for i in range(30):
    if i ==1 or i==28:
        if number!=10:
            print(card[i].format(sign+" "," "+sign))
        else:
            print(card[i].format(sign,sign))
    elif i > 2 and i < 26:
        if i%6==2:
            print(card[i])
            count-=3
            continue
        if count>2:
            print(card[i].format(mapa[vstup[3]][(i-3)%6],mapa[vstup[3]][(i-3)%6],mapa[vstup[3]][(i-3)%6]))
        elif count > 1:
            print(card[i].format(mapa[vstup[3]][(i-3)%6],"     ",mapa[vstup[3]][(i-3)%6]))
        elif count > 0:
            print(card[i].format("     ",mapa[vstup[3]][(i-3)%6],"     "))
        else:
            print(card[i].format("     ","     ","     "))
    else:
        print(card[i])
