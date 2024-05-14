plain = input()
key = input()

for i in range(len(plain)):
    num = ord(key[i%len(key)])-ord('a')+1
    answer = ord(plain[i])-num
    if ord('a')>(answer):
        answer += 26
    if plain[i] == ' ':
        print(" ", end='')
    else:
        print(chr(answer), end='')