# **ABSTRACT DATA TYPES**

Abstract Data Types (**ADTs**) are *mathematical models* that define a set of **data** and the **operations** that can be performed on that data. They focus on **behavior**, emphasizing *what* the data can do, rather than *how* it is internally represented.

### **Key Concepts**
- **Values** – The data types an ADT can hold.
- **Operations** – The actions that can be performed on the data.
- **Results & Behavior** – The outcomes and effects of performing operations on the data.

## **Key Characteristics**
- **Abstraction** – The internal representation is *hidden* from the user.
- **Encapsulation** – Bundles the *data* and *operations* together.
- **Modularity** – Allows for *easy code reuse* and *maintenance*.

## **Common ADTs**
- **List, Stack, Queue, Priority Queue**
- **Trees**
- **Set, Sequence, Map**
- **Dictionary**

> *Note: We will use C / C++ to implement ADTs.*

## **ADT Specification**
The *specification* of an ADT describes how its implementation behaves in terms of **inputs and outputs**.

### **Specifications Consist Of:**
1. **Calling Prototype**
   - *Name of the operation*
   - *Parameters* and their **types**
   - *Return values* and their **types**
2. **Preconditions**
   - Conditions *assumed to be true* when the operation is called.
3. **Postconditions**
   - Conditions *assumed to be true* when the operation is completed or returns.

## **Operations on ADTs**
ADTs support various types of operations:

1. **Constructors** – *Create* a new object and return a reference to it.
2. **Access Functions** – *Return information* about the object *without modification*.
3. **Manipulation Procedures** – *Modify* the object without returning information.
4. **State** – The *current value* of the object's data.
5. **Destructor** – *Deallocates* the object from memory.
