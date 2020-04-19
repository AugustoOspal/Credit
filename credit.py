counter1 = []
counter2 = []

card_number = input("Number: ")

while not card_number.isdigit():

    card_number = input("Number: ")

card_number = str(card_number)

for i in range(len(card_number)):

    if i % 2 != 0:

        counter1.append(int(card_number[i]))

    else:

        counter2.append(int(card_number[i]))

for i in range(len(counter1)):

    if counter1[i] * 2 > 10:

        pull_apart = str(counter1[i] * 2)
        counter1[i] = int(pull_apart[0])
        counter1.append(int(pull_apart[1]))

    else:

        counter1[i] = counter1[i] * 2

total_num = sum(counter1) + sum(counter2)

valid_invalid = False

if total_num % 10 == 0:

    valid_invalid = True

total_num = str(total_num)

# VISA
if card_number == '4' and valid_invalid == True:

    print("VISA\n")

# MASTERCARD
elif card_number[0] == "5" and card_number[1] in ['1', '2', '3', '4', '5'] and valid_invalid == True:
    
    print("MASTERCARD\n")

# AMERICAN EXPRESS
elif card_number[0] == '3' and card_number[1] in ['4', '7'] and valid_invalid == True:

    print("AMEX\n")

else:
    print("INVALID")
