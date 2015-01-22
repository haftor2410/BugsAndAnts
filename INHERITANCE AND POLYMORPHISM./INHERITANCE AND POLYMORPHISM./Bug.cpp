#include "Bug.h"
#include "World.h"
using namespace std;

Bug::Bug(World* aWorld, int xcoord, int ycoord) : Organism(aWorld, xcoord, ycoord){
    myMoves = 0;
    notEatenRounds = 0;
}

char Bug::representation() const{
    return 'X';
}
OrganismType Bug::getType() const{
    return BUG;
}

int Bug::size() const{
    return 30;
}

void Bug::generateOffspring(int whereX, int whereY){
    //by til nyjan BUG og det breedNextTime = false;
    setBreedNextTime(false);
    new Bug(world, whereX, whereY);
}

bool Bug::isDead() const{
    //Bug deyr ef hann hefur ekki bordad i 3 umferdir
    if(notEatenRounds >= STARVE_BUGS){
        return true;
    }
    return false;
}

void Bug::breed(){
    //breed'ar bara ef hann a ad breed'a
    //eda hann atti ad breeda i sidustu umferd en gat tad ekki
    if(getBreed() >= BREED_BUGS || breedNextTime == true){
        breedAtAdjacentCell();
        setBreedToZero();
    }
}


void Bug::move(){
    //haekka myMoves
    myMoves++;
    //ef BUG getur bordad UP ta gerir hann tad
    if(bugTryToEat(x, y + 1)){
        //setur svo notEatenRounds = 0
        notEatenRounds = 0;
    }
    //ef BUG getur bordad DOWN ta gerir hann tad
    else if(bugTryToEat(x, y - 1)){
        notEatenRounds = 0;
    }
    //ef BUG getur bordad LEFT ta gerir hann tad
    else if(bugTryToEat(x - 1, y)){
        notEatenRounds = 0;
    }
    //ef BUG getur bordad RIGHT ta gerir hann tad
    else if(bugTryToEat(x + 1, y)){
        notEatenRounds = 0;
    }
    else{
        //Ef BUG getur ekkert bordad ta faerist hann random eins og ANT
        notEatenRounds++;
        Move temp = world->randomMove();
        
        if(temp == UP){
            actualMove(x, y + 1);
        }
        if(temp == DOWN){
            actualMove(x, y - 1);
        }
        if(temp == LEFT){
            actualMove(x - 1, y);
        }
        if(temp == RIGHT){
            actualMove(x + 1, y);
        }
    }
}

//hjalparfall sem leatur BUG borda ANT
bool Bug::bugTryToEat(int inputX, int inputY){
    //ef reiturinn er a grid'inu
    if(leagalPositionOrg(inputX, inputY)){
        //ef hann er ekki NULL
        if(world->getAt(inputX, inputY) != NULL){
            //ef ANT er a reitnum
            if(world->getAt(inputX, inputY)->getType() == ANT){
                //eyði ANT
                delete world->getAt(inputX, inputY);
                //set nyja grid'id = gamla grid'id
                world->setAt(inputX, inputY, world->getAt(x, y));
                //NULL'a svo gamla
                world->setAt(x, y, NULL);
                //faeri svo
                movesTo(inputX, inputY);
                //returna TRUE til ad vita ad BUG hefur bordad
                return true;
            }
        }
    }
    return false;
}
