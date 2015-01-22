#ifndef INHERITANCEANDPOLYMORPHISMBug
#define INHERITANCEANDPOLYMORPHISMBug

#include "Organism.h"
#include <iostream>

class Bug : public Organism{
public:
    Bug(World* aWorld, int xcoord, int ycoord);
    virtual void move();
    
    // Makes this organism breed.
    virtual void breed();
    
    // Returns the type of this organism.
    virtual OrganismType getType() const;
    
    // The character representation of this organism.
    virtual char representation() const;
    
    // The size of this organism.
    virtual int size() const;
    
    // Returns true if organism is dead, false otherwise.
    virtual bool isDead() const;
    
    //hjalparfall fyrir BUG til ad borda
    bool bugTryToEat(int inputX, int inputY);
    
protected:
    // Generates an offspring at the given position.
    virtual void generateOffspring(int whereX, int whereY);
    
    int myMoves;
    
    //geymir hvad er langt sidan BUG bordadi sidast
    int notEatenRounds;
    
};


#endif /* defined(__INHERITANCE_AND_POLYMORPHISM__Bug__) */
