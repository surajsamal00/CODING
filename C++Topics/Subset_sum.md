# ✨ Heaven Splitting Earth Shattering Bitset Technique

Let's say you want to find what combinations of sums you can make with some (all or none) elements from an array:

```cpp
[5, 7, 6, 2]
```

We use a **boolean bitmask representation** to track possible sums. The **maximum possible sum** is:

```
5 + 7 + 6 + 2 = 20
```

So we need **21 bits** (from 0 to 20).

---

## 🔖 Step 1: Initialization

We initialize the availability bitmask:

```
avail = 000000000000000000001
                            ↑
                            bit 0 set because 0 sum is always possible
```

---

## ➕ Step 2: Add First Element (5)

We shift the current bitmask left by 5:

```
new = avail << 5 = 000000000000000100000
```

This sets **bit 5**, meaning **sum 5** is now possible.

Now OR it with the original:

```
avail |= new = 000000000000000100001
```

Now **sums 0 and 5** are available.  

---
<br><br><br>

---
## ➕ Step 3: Add Second Element (7)

```
new = avail << 7 = 000000001000010000000
```

This sets **bits 7 and 12**, meaning **sums 7 and 12** are now possible.

OR it again:

```
avail |= new = 000000001000010100001
```

Now **sums 0, 5, 7, and 12** are available.

---

## ➕ Step 4: Add Third Element (6)

```
new = avail << 6 = 001000010100001000000
```

This sets **sums 6, 11, 13, 18**.

OR it:

```
avail |= new = 001000011100011100001
```

Now **sums 0, 5, 6, 7, 11, 12, 13, 18** are available.

---

## ➕ Step 5: Add Fourth Element (2)

```
new = avail << 2 = 100001110001110000100
```

Now **sums 2, 7, 8, 9, 13, 14, 15, 20** are available.

Final OR:

```
avail |= new = 101001111101111100101
```

---
<br><br>

## 🔹 Final Result



```
1   0   1   0   0   1   1   1   1   1   0   1  1  1  1  1  0  0  1  0  1
20  19  18  17  16  15  14  13  12  11  10  9  8  7  6  5  4  3  2  1  0

```

The subset sums we can make from `[5, 7, 6, 2]` are:

```
0, 2, 5, 6, 7, 8, 9, 11, 12, 13, 15, 18, 20
```


Achieved using only bit shifts and ORs — **faster and cleaner than classic Dao**.

This is the **Heaven Splitting Earth Shattering Bitset Technique**.

---

> Fast, elegant, and jade-swan worthy. Cultivate wisely.<br>
> *– Immortal Mystic Master*



cpp```

bitset<21> bit(1);
vector<int> a{5,7,6,2};
for(auto n:a) {
    bit |= (bit<<n);
}
for(int i=0; i<=20; i++){
    if(bit[i]){
        cout << i << " ";
    }
}
```
