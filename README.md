Smart Cart Undo System Using Stack (LIFO)

2.1 Project Title

Smart Cart Undo System Using Stack (LIFO)

A console-based C++ application that implements an Undo mechanism for an e-commerce order management system using the Stack data structure. The project demonstrates the practical application of the Last In First Out (LIFO) principle in managing customer actions before order confirmation.

⸻

2.2 Problem Statement

In an e-commerce platform, customers frequently perform actions such as adding products, updating quantities, applying discount coupons, and changing delivery addresses. These modifications are sometimes made accidentally and need to be reverted before placing the final order.

The system addresses this problem by storing every customer action in a Stack and providing an Undo feature that removes the most recent action first, ensuring quick and efficient error correction.

⸻

2.3 Objectives

The primary objectives of this project are:

* To implement the Stack data structure using C++ STL.
* To demonstrate Push, Pop, and Peek operations in a real-world application.
* To provide an efficient Undo functionality for customer actions.
* To improve order accuracy before confirmation.
* To develop a simple, interactive, and menu-driven console application.

⸻

2.4 System Overview / Architecture

The application follows a simple workflow where every customer action is recorded in a Stack. Whenever the user performs an operation such as adding a product or applying a coupon, the action is pushed onto the Stack. If the Undo option is selected, the latest action is removed using the Pop operation and the previous order state is restored.

Workflow:

Customer → Order Operation → Stack Storage → Undo Manager → Order Confirmation

The system also provides action history, current order details, and order confirmation to simulate a basic e-commerce environment.

⸻

2.5 Data Structures and Algorithms Used

Data Structure

Stack (STL)

The Stack follows the Last In First Out (LIFO) principle, making it suitable for implementing Undo functionality.

Operations Used

Operation	Purpose
Push()	Store a new customer action
Pop()	Remove the latest action
Top()	Display the last action
Empty()	Check whether the stack is empty

⸻

2.6 Implementation Approach

The project is implemented as a menu-driven console application.

1. The user selects an operation from the dashboard.
2. Every modification is stored in the Stack using Push().
3. The latest action can be viewed using Peek (Top()).
4. Undo removes the latest action using Pop().
5. The application displays the updated order details.
6. Once the order is confirmed, further modifications are disabled.

This approach provides an efficient and practical implementation of Stack operations.

⸻

2.7 Time and Space Complexity Analysis

Operation	Time Complexity
Push	O(1)
Pop	O(1)
Peek (Top)	O(1)
Display History	O(n)

Space Complexity: O(n)

where n represents the total number of customer actions stored in the Stack.

⸻

2.8 Execution Steps

1. Launch the application.
2. Display the Smart Cart Dashboard.
3. Select an operation such as Add Product or Apply Coupon.
4. Store the action in the Stack.
5. Perform Undo if required.
6. View the updated order details.
7. Confirm the order.
8. Display the final order summary and exit the application.

⸻

2.9 Sample Input and Output

Sample Input

Enter Choice : 1
Product Name : Laptop
Enter Choice : 3
Coupon Code : SAVE20
Enter Choice : 6

Sample Output

Product Added Successfully.
Coupon Applied Successfully.
Undo Successful.
Removed : Apply Coupon
Current Order:
Product : Laptop
Quantity : 1
Coupon : None

⸻

2.10 Screenshots

The following screenshots can be included in the report:


<img width="979" height="855" alt="image" src="https://github.com/user-attachments/assets/2659b83b-485b-4b68-9c14-818a85c602ca" />

<img width="979" height="855" alt="image" src="https://github.com/user-attachments/assets/2e12fdb2-15b6-4db5-a410-2cc52da0486c" />

<img width="979" height="855" alt="image" src="https://github.com/user-attachments/assets/fbe2162e-35fd-4b04-ac37-5859af514efc" />

<img width="979" height="855" alt="image" src="https://github.com/user-attachments/assets/caa5b443-b012-4646-8930-cd7d4ae57f43" />

<img width="979" height="498" alt="image" src="https://github.com/user-attachments/assets/db6f5dc3-1064-476a-baf7-cf99863c06b6" />

⸻

2.11 Results and Observations

The project successfully demonstrates the implementation of the Stack data structure in a real-world e-commerce scenario. Push, Pop, and Peek operations are executed efficiently, while the Undo functionality correctly follows the LIFO principle. The interactive console interface, order summary, and action history improve usability and provide a clear understanding of Stack operations.

⸻

2.12 Conclusion

The Smart Cart Undo System effectively applies the Stack data structure to solve the common problem of accidental order modifications in e-commerce applications. By utilizing the LIFO principle, the system provides a reliable Undo mechanism with constant-time Push, Pop, and Peek operations. The project serves as a practical demonstration of Data Structures and Algorithms while maintaining simplicity, efficiency, and user-friendly interaction.










