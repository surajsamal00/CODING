def construct_permutation(n, s):
    stable = [i+1 for i in range(n) if s[i] == '1']
    unstable = [i+1 for i in range(n) if s[i] == '0']
    
    # Place stable first (sorted automatically), then unstable
    p = stable + unstable[::-1]   # reverse unstable to "break" binary search
    
    return p

# Example usage
n = 5
s = "10101"
p = construct_permutation(n, s)
print(p)   # e.g. [1, 3, 5, 4, 2]
