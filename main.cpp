#include <iostream>
#include <cassert>
#include <vector>

class Branch
{
    std::string ownerName = "None";

public:
    //int countNeighbor = 0;
    Branch(std::string inNewName = "None")
    {
        if (inNewName != "None" && !inNewName.empty()) {
            ownerName = inNewName;
        }
    }

    std::string getName ()
    {
        return this->ownerName;
    }
};

class BigBranch
{
    int count = 0;
    Branch** mediumBranch = nullptr;
    std::string ownerName = "None";
public:

    BigBranch (int inCount): count(inCount)
    {
        assert(inCount >= 0);
        mediumBranch = new Branch*[inCount];
        std::cout << "Enter big branch owners name: ";
        std::cin >> this->ownerName;
        for (int i = 0; i < inCount; i++)
        {
            std::string name;
            std::cout << "Enter medium branch owners name: ";
            std::cin >> name;
            mediumBranch[i] = new Branch(name);
        }
    }

    std::string getName ()
    {

        return this->ownerName;
    }
    int searchName(std::string searchName)
    {
        bool isName = false;
        for (int i = 0; i < count; i++)
        {
            if (mediumBranch[i]->getName() == searchName) isName = true;
        }
        if (this->ownerName == searchName) isName = true;
        if (isName)
        {
            int countNeighbour = 0;
            for (int i = 0; i < count; i++)
            {
                if (mediumBranch[i]->getName() != "None") countNeighbour++;
            }
            countNeighbour += this->ownerName != "None";
            return countNeighbour;
        }
    }

    int countNeighbor()
    {
        int amount = 0;
        for (int i = 0; i < count; i++)
        {
            if (mediumBranch[i]->getName() != "None") amount++;
        }
        return amount;
    }

};



class Tree
{
    int count = 0;
    std::vector<BigBranch*> bigBranch{1};

public:
    Tree (int inCount): count(inCount)
    {
        assert(inCount >= 0);
        //bigBranch = new BigBranch*[inCount];

        for (int i = 0; i < inCount; i++)
        {
            int countMedium = 2 + rand() % (3 - 2);
            bigBranch[i] = new BigBranch(countMedium);
            bigBranch.push_back(bigBranch[i]);
        }
    }

    int getCountNeigbour(std::string searchName)
    {
        for(int i = 0; i < count; i++)
        {
            int amount = bigBranch[i]->searchName(searchName) > 0;
            if (amount)
            {
                std::cout << searchName << " has " <<  amount << " neighbour" ;
                return amount;
            }
        }
    }
};



int main() {
    int countBig = 3 + rand() % (5 - 3);
    //BigBranch** bigBranch = new BigBranch*[countBig];
    Tree* tree = new Tree(countBig);

    std::cout << "Enter search name: ";
    std::string searchName;
    std::cin >> searchName;

    tree->getCountNeigbour(searchName);
    return 0;
}
