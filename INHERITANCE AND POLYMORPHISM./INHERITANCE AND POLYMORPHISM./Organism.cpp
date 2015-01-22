#include <iostream>
#include "Organism.h"
#include "World.h"
using namespace std;

// Create an organism at the given coordinates in the given world.
Organism::Organism(World* aWorld, int xcoord, int ycoord) {
    world = aWorld;
    x = xcoord;
    y = ycoord;
    breedNextTime = false;
    breedTicks = 0;
    moved = false;
    world->setAt(x, y, this);
}

//hjalparfall til ad hafa kodan laesinlegri
void Organism::setBreedNextTime(bool Xor){
    breedNextTime = Xor;
}

//hjalparfall til ad hafa kodan laesinlegri
bool Organism::getBreedNextTime(){
    return breedNextTime;
}

// flags the organism as moved or not
void Organism::setMoved(bool hasMoved) {
    moved = hasMoved;
}

// has the organism moved or not?
bool Organism::hasMoved() const {
    return moved;
}

// moves the organism from coordinates (x,y) to (xNew,yNew)
void Organism::movesTo(int xNew, int yNew) {
    
    x = xNew;
    
    y = yNew;
    
    setMoved(true);
    
    breedTicks++;
}

// Breeds an organism at an adjacent cell. This method calls the
// generateOffspring() method.
void Organism::breedAtAdjacentCell()  {
    //ef nyja stadan er ekki upptekin og er a grid'inu
    if(world->getAt(x, y + 1) == NULL && leagalPositionOrg(x, y + 1)){
        //kalla i generateOfspring og set breedTicks = 0;
        generateOffspring(x, y + 1);
        setBreedToZero();
    }
    else if(world->getAt(x, y - 1) == NULL && leagalPositionOrg(x, y - 1)){
        generateOffspring(x, y - 1);
        setBreedToZero();
    }
    else if(world->getAt(x - 1, y) == NULL && leagalPositionOrg(x - 1, y)){
        generateOffspring(x - 1, y);
        setBreedToZero();
    }
    else if(world->getAt(x + 1, y) == NULL && leagalPositionOrg(x + 1, y)){
        generateOffspring(x + 1, y);
        setBreedToZero();
    }
    else{
        //ef tad er ekkert laust i kring ta er bool breyta man tad
        //til þess að muna ad tad a ad breeda naest
        setBreedNextTime(true);
    }
    
}

// Returns true if organism is dead, false otherwise.
bool Organism::isDead() const {
    return false;
}

int Organism::getBreed(){
    return breedTicks;
}

void Organism::setBreedToZero(){
    breedTicks = 0;
}

//hjalparfall sem ser um ad feara baedi ANTS og BUGS
void Organism::actualMove(int inputX, int inputY){
    //ef stadsettningin er a gridinu og reiturinn er ekki upptrekin
    if(leagalPositionOrg(inputX, inputY) && world->getAt(inputX, inputY) == NULL){
        //set nyja grid'id = gamla grid'id
        world->setAt(inputX, inputY, world->getAt(x, y));
        //NULL'a svo gamla
        world->setAt(x, y, NULL);
        //faeri svo
        movesTo(inputX, inputY);
    }
    else{
        //ef allt er upptekid ta set eg moved = true
        //og haekka breedTicks
        setMoved(true);
        breedTicks++;
    }

}


//hjalparfall til ad sja hvort stada se a grid'inu
bool Organism::leagalPositionOrg(int xCord, int yCord){
    if(xCord >= 0 && xCord < WORLDSIZE){
        if(yCord >= 0 && yCord < WORLDSIZE){
            return true;
        }
    }
    return false;
}
