#include "Ant.h"
#include "World.h"
#include <iostream>
using namespace std;

Ant::Ant(World* aWorld, int xcoord, int ycoord) : Organism(aWorld, xcoord, ycoord){
    
}


char Ant::representation() const{
    return 'o';
}
OrganismType Ant::getType() const{
    return ANT;
}

void Ant::breed(){
    //breed'ar ekki nema ant ant a ad breeda
    if(getBreed() >= BREED_ANTS || breedNextTime == true){
        //kallar a breed a naesta lausa reit
        breedAtAdjacentCell();
        
        setBreedToZero();
    }
}

void Ant::generateOffspring(int whereX, int whereY){
    //byr til nyjan ant og setur breedNextTime = false
    setBreedNextTime(false);
    new Ant(world, whereX, whereY);
}

int Ant::size() const{
    return 10;
}

// Nota ekkert þetta fall
bool Ant::isDead() const{
    return false;
}

void Ant::move(){

    Move temp = world->randomMove();
    if(temp == UP){
        //kalla a fallid actual move og sendi inn UP hnitin
        actualMove(x, y + 1);
    }
    if(temp == DOWN){
        //kalla a fallid actual move og sendi inn DOWN hnitin
        actualMove(x, y - 1);
    }
    if(temp == LEFT){
        //kalla a fallid actual move og sendi inn LEFT hnitin
        actualMove(x - 1, y);
    }
    if(temp == RIGHT){
        //kalla a fallid actual move og sendi inn RIGHT hnitin
        actualMove(x + 1, y);
    }
}