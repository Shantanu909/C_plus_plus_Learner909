#include <iostream>
using namespace std;

const int totalSeats = 10;
int seats[totalSeats] = {-1}; 

void allocateSeat(int enrollmentNo) {
    int seat = enrollmentNo % totalSeats; 
    int originalSeat = seat;
    while (seats[seat] != -1) { 
        seat = (seat + 1) % totalSeats;
        if (seat == originalSeat) {
            cout << "No  seats!" ;
            return;
        }
    }
    seats[seat] = enrollmentNo;
    cout << "Allocated seat " << seat << " to student with enrollment number " << enrollmentNo ;
	cout<<"/n";
}

void displaySeatStatus() {
    cout << "Seat Status:" ;
    for (int i = 0; i < totalSeats; i++) {
        if (seats[i] != -1) {
            cout << "Seat " << i << " is occupied by student with enrollment number " << seats[i] ;
        } else {
            cout << "Seat " << i << " is unoccupied" ;
        }
    }
}

int main() {
    while (true) {
        int enrollmentNo;
        cout << "Enter enrollment number (or -1 to exit): ";
        cin >> enrollmentNo;
        if (enrollmentNo == -1) {
            break;
        }
        allocateSeat(enrollmentNo);
        displaySeatStatus();
    }
    return 0;
}
