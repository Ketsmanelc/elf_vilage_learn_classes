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

class BigBranch //: public Branch
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


#if 0
class Tree: public BigBranch
{
    int count = 0;
    BigBranch** bigBranch= nullptr;

public:
    Tree (int inCount): count(inCount)
    {
        assert(inCount >= 0);
        bigBranch = new BigBranch*[inCount];
        for (int i = 0; i < inCount; i++)
        {
            std::string name;
            std::cin >> name;
            bigBranch[i] = new BigBranch(name);
        }
    }
}
public:
#endif

int main() {
    int countBig = 3 + rand() % (5 - 3);
    BigBranch** bigBranch = new BigBranch*[countBig];
    for (int i = 0; i < countBig; i++)
    {
        int countMedium = 2 + rand() % (3 - 2);
        bigBranch[i] = new BigBranch(countMedium);
    }

    std::cout << "Enter search name: ";
    std::string searchName;
    std::cin >> searchName;
    for (int i = 0; i < countBig; i++)
    {
        if (searchName == bigBranch[i]. )

            bigBranch[i]->countNeighbor();
    }

    return 0;
}
