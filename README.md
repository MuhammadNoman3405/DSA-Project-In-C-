# Faisal's Travel Agency - Ticket Management System

A robust **C++ CLI application** designed to manage flight bookings using **Doubly Linked Lists**. This project demonstrates the practical application of Data Structures and Algorithms (DSA) in a real-world scenario, specifically focusing on memory management and efficient data traversal.

## 🚀 Features

* **Seat Booking & Purchasing**: Users can book tickets for different airlines (PIA, Fly Emirates) and classes (Business, Economy).
* **Automatic Discounts**: Integrated logic to apply a 10% discount for immediate purchases.
* **CRUD Operations**:
* **Create**: Add new passenger details to the tail of the list.
* **Read**: Display all records or search for specific users by ID.
* **Update**: Modify existing passenger contact information.
* **Delete**: Cancel tickets and free up memory.


* **Dynamic Sorting**: Toggle the display order between **Ascending** and **Descending** using pointer manipulation.
* **Revenue Summary**: Calculate total agency revenue based on ticket status.
* **File Export**: Generate a `Summary.docs` file containing all transaction details for record-keeping.

## 🛠️ Data Structures Used

This project utilizes a **Doubly Linked List** to store passenger nodes. Each node contains:

* Passenger Personal Info (Name, Phone, Email)
* Travel Details (Airlines, Class, Destination, Date)
* Pointers (`*next`, `*prev`) for bidirectional navigation.

## 💻 Technologies Used

* **Language**: C++
* **Concepts**: OOP (Classes & Objects), Linked Lists, File I/O (`fstream`), Pointers.
* **Tools**: Dev-C++ / VS Code.

## 📥 Installation & Usage

1. **Clone the Repository**:
```bash
git clone https://github.com/YourUsername/Travel-Management-System.git

```


2. **Compile the Code**:
```bash
g++ main.cpp -o TravelSystem

```


3. **Run the Application**:
```bash
./TravelSystem

```



## 📜 Future Enhancements

* Add a Graphical User Interface (GUI) using Qt or SFML.
* Implement a login system for Admin and Customers.
* Integrate a database like SQLite for permanent storage.

---

**Developed by [Noman]** *BSCS Student at UET Taxila*

