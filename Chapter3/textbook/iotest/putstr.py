import random
import string

if __name__ == "__main__":
    with open("putstr.txt",'w') as f:
        for _ in range(1000):
            str_len = random.randint(1,10000)
            x = string.ascii_letters
            new_str = ''.join([random.choice(x) for _ in range(str_len)]) 
            # random.sample() is to pick a subset of the input sequence
            # randomly, without picking any one element more than once. 
            f.write(new_str)
            f.write('\n')