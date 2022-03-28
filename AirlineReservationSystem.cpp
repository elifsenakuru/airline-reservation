#include "AirlineReservationSystem.h"

void AirlineReservationSystem::addPassenger(const std::string &firstname, const std::string &lastname) {
    /* TODO */
    Passenger p1 = Passenger(firstname,lastname);
    passengers.insert(p1);
}

Passenger *AirlineReservationSystem::searchPassenger(const std::string &firstname, const std::string &lastname) {
    /* TODO */
    
    Passenger p1 = Passenger(firstname,lastname);
    BSTNode<Passenger> *tmp2 = passengers.search(p1);
    if(tmp2!=NULL){
        return &(tmp2->data);
    }
    else{
        return NULL;
    }
    
}

void AirlineReservationSystem::addFlight(const std::string &flightCode, const std::string &departureTime, const std::string &arrivalTime, const std::string &departureCity, const std::string &arrivalCity, int economyCapacity, int businessCapacity) {
    /* TODO */
    Flight f1 = Flight(flightCode, departureTime,arrivalTime,departureCity,arrivalCity,economyCapacity,businessCapacity);
    if(flights.search(f1) == NULL){
        flights.insert(f1);
    }
}

std::vector<Flight *> AirlineReservationSystem::searchFlight(const std::string &departureCity, const std::string &arrivalCity) {
    /* TODO */
}

void AirlineReservationSystem::issueTicket(const std::string &firstname, const std::string &lastname, const std::string &flightCode, TicketType ticketType) {
    /* TODO */
}

void AirlineReservationSystem::saveFreeTicketRequest(const std::string &firstname, const std::string &lastname, const std::string &flightCode, TicketType ticketType) {
    /* TODO */
    /*Passenger *p1 = searchPassenger(firstname,lastname);
    Flight *f1 = searchFlight(flightCode);
    if(p1 == NULL || f1==NULL){
        return;
    }
    Ticket t1 = Ticket(p1, f1, ticketType);*/
}

void AirlineReservationSystem::executeTheFlight(const std::string &flightCode) {
    /* TODO */
}

void AirlineReservationSystem::print() const {
    std::cout << "# Printing the airline reservation system ..." << std::endl;

    std::cout << "# Passengers:" << std::endl;
    passengers.print(inorder);

    std::cout << "# Flights:" << std::endl;
    flights.print(inorder);

    std::cout << "# Free ticket requests:" << std::endl;
    freeTicketRequests.print();

    std::cout << "# Printing is done." << std::endl;
}
