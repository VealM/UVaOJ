import random

if __name__ == "__main__":
    with open("plus.txt",'w') as f:
        for _ in range(100000):
            lo , hi = -100000, 100000
            a, b =random.randint(lo, hi), random.randint(lo, hi)
            f.write("{} {}".format(str(a),str(b)))
            f.write("\n")
