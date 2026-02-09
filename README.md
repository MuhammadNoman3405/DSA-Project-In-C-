# ✈️ Travel Management System (DSA Implementation)

A specialized C++ application developed to manage flight reservations using high-performance **Doubly Linked List** data structures. This project focuses on efficient memory management and bidirectional data traversal.

---

## 📊 Technical Architecture

This project implements a **Doubly Linked List (DLL)** rather than a standard array or singly linked list. 

**Why DLL?**
- **Bidirectional Navigation**: Each node contains `next` and `prev` pointers, allowing us to traverse the passenger list in both directions.
- **Efficient Deletion**: Unlike arrays, we don't need to "shift" elements. We simply re-route the pointers, which is much faster ($O(1)$ if the node is known).
- **Dynamic Growth**: Memory is allocated on the heap only when a new passenger is added, preventing wasted space.



---

## 🌟 Features

- **✅ Smart Booking**: Categorizes users by Airline (PIA/Emirates) and Class (Business/Economy).
- **💸 Real-time Pricing**: Integrated logic to calculate costs and apply a **10% discount** for instant purchases.
- **🔄 Dynamic Reversing**: Uses a recursive algorithm to flip the order of bookings (Ascending vs. Descending).
- **🔍 Fast Search**: Search for passenger records instantly by their Unique ID.
- **📄 Report Generation**: Automatically exports a `Summary.docs` file containing the total revenue and passenger list.

---

## 🛠️ Installation & Execution

1. **Clone the project:**
   ```bash
   git clone [https://github.com/MuhammadNoman3405/DSA-Project-In-C-](https://github.com/MuhammadNoman3405/DSA-Project-In-C-)

```

2. **Compile using G++:**
```bash
g++ main.cpp -o travel_system

```


3. **Run the executable:**
```bash
./travel_system

```



---

## 🚀 Future Roadmap

* [ ] Implement **Merge Sort** on the Linked List for alphabetical sorting.
* [ ] Add a **Queue-based waiting list** for fully booked flights.
* [ ] Connect a **Streamlit** dashboard for a modern web UI.

---

**Developed with ❤️ by Noman** *BSCS @ UET Taxila | Data Science & ML Enthusiast*

