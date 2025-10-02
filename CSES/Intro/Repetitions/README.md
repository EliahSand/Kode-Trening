## **Analysis**

### **Time Complexity**

#### **Big O Notation:**

- **Reasoning**:
  - O(n) because one for loop to n

---

### **Spatial Complexity**
- O(1) because one variable


#### **Solution**
Maintain a variable count to store the running count of the contiguous character.
Iterate over the string, if the current character is same as the previous character, increment count by 1.
Otherwise reset count to 1.
Also keep checking for the maximum value of count and store it in ans.
After iterating over the entire string, return ans as the final result.
