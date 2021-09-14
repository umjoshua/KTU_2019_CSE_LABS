/* Doubly linked list operations in java*/
import java.util.*;
class DoublyLinkedList{
    class Node{
        int item;
        Node previous;
        Node next;
        public Node(int item){
            this.item=item;
        }
    }
    Node head, tail=null;
public void AddAtStart(int data){
    Node newNode = new Node(data);
    if(head == null){
        head = tail = newNode;
        head.previous = null;
        tail.next = null;
    }
    else{
        head.previous = newNode;
        newNode.next = head;
        newNode.previous = null;
        head = newNode;
    }
}
public void AddAtEnd(int data)
    {
        Node newNode = new Node(data);
        Node temp= head;
        if(head == null)
        {
            head= tail= newNode;
            head.previous = null;
            tail.next = null;
        }
        else
        {
            while(temp.next!=null)
                temp=temp.next;
            temp.next = newNode;
            newNode.previous = temp;
            temp = newNode;
            temp.next = null;
        }
}
void AddAtPos(int data, int pos){
    Node newNode = new Node(data);
    newNode.next = null;
    newNode.previous = null;
    if(pos < 0){
        System.out.print("\nPosition should be >= 0");
    }
    else if (pos == 0){
        newNode.next = head;
        head.previous = newNode;
        head = newNode;
    }
    else {
        Node temp = new Node(data);
        temp = head;
        for(int i =0; i< pos-1; i++){
            if(temp!=null){
                temp = temp.next;
            }
        }
        if(temp != null){
            newNode.next = temp.next;
            newNode.previous = temp;
            temp.next = newNode;
            if(newNode.next != null){
                newNode.next.previous = newNode;
            }
            else{
                System.out.print("\nThe previous node is null.");
            }
        }
    }
}
void deleteAtPos(int pos){
    if(head == null || pos<0){
        System.out.print("\nPosition should be >=0");
        return;
    }
    Node current = head;
    for(int i=0; current != null && i<pos; i++){
        current = current.next;
    }
    if(current == null){
        System.out.print("\nNo such position exist!!");
        return;
    }
    if(head == current)
        head = current.next;
    if(current.next!=null)
        current.next.previous=current.previous;
    if(current.previous!=null)
        current.previous.next=current.next;
    current=null;
}
void deleteElement(int data){
    if(head == null){
        System.out.print("\nList is empty");
        return;
    }
    Node current = head;
    while(current!=null){
        if(current.item==data)
            break;
        current=current.next;
    }
    if(current == null){
        System.out.print("\nNo such element exist!!");
        return;
    }
    if(head == current)
        head = current.next;
    if(current.next!=null)
        current.next.previous=current.previous;
    if(current.previous!=null)
        current.previous.next=current.next;
    current=null;
}
public void printNodes(){
    Node current = head;
    if(head == null) {
        System.out.print("\nDoubly linked list is empty");
        return;
    }
    System.out.print("\nNodes of doubly linked list: ");
    while(current != null){
        System.out.print(current.item + " ");
        current = current.next;
    }
    System.out.print("\n");
}
}
class dbly_linkedlist{
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        DoublyLinkedList dl_list = new DoublyLinkedList();
        char ch;
        System.out.println("Doubly linked list operations \n");
        do{
            System.out.println("1. Insert at beginning");
            System.out.println("2. Insert at end");
            System.out.println("3. Insert at position ");
            System.out.println("4. Delete at position");
            System.out.println("5. Delete an element");
            System.out.println("6. Display");
            System.out.print("Enter your choice: ");
            int choice = s.nextInt();
            switch (choice) {
                case 1:
                    System.out.print("Enter element to insert: ");
                    dl_list.AddAtStart(s.nextInt() );
                    dl_list.printNodes();                   
                    break;
                case 2:
                    System.out.print("Enter element to insert: ");
                    dl_list.AddAtEnd(s.nextInt() );
                    dl_list.printNodes();
                    break;
                case 3:
                    System.out.print("Enter element: ");
                    int d = s.nextInt();
                    System.out.print("Enter position: ");
                    int p = s.nextInt();
                    dl_list.AddAtPos(d,p);
                    dl_list.printNodes();
                    break;
                case 4:
                    System.out.print("Enter position : ");
                    int pos=s.nextInt();
                    dl_list.deleteAtPos(pos);
                    dl_list.printNodes();
                    break;
                case 5:
                    System.out.print("Enter element to delete: ");
                    dl_list.deleteElement(s.nextInt() );
                    dl_list.printNodes();
                    break;
                case 6:
                    dl_list.printNodes();
                    break;
            }
            System.out.println("Continue? Y/N");
            ch = s.next().charAt(0);
        }while(ch == 'Y' || ch == 'y');
    }
}