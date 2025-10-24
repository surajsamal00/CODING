import random

# Parameters
T = 10000          # number of test cases
min_n, max_n = 1, 1000
min_q, max_q = 1, 100

with open("testcase.txt", "w") as f:
    f.write(f"{T}\n")
    for _ in range(T):
        n = random.randint(min_n, max_n)
        q = random.randint(min_q, max_q)
        f.write(f"{n} {q}\n")
        
        # Generate random 0/1 array
        a = [random.randint(0,1) for _ in range(n)]
        f.write(" ".join(map(str, a)) + "\n")
        
        # Generate random queries
        for _ in range(q):
            l = random.randint(1, n)
            r = random.randint(l, n)
            f.write(f"{l} {r}\n")

print("testcase.txt successfully generated!")
