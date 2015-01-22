#ifndef INHERITANCEANDPOLYMORPHISMAnt
#define INHERITANCEANDPOLYMORPHISMAnt

#include "Organism.h"
#include "World.h"
#include <iostream>

class Ant : public Organism{
public:
    Ant(World* aWorld, int xcoord, int ycoord);
    
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

    
protected:
    // Generates an offspring at the given position.
    virtual void generateOffspring(int whereX, int whereY);

    
};


#endif /* defined(__INHERITANCE_AND_POLYMORPHISM__Ant__) */
