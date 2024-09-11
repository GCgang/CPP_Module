#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource default constructor" << std::endl;
    for (int idx = 0; idx < MAX_SLOT; idx++)
    {
        mInventory[idx] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& materiaSource)
{
    std::cout << "MateriaSource copy constructor" << std::endl;
    for (int idx = 0; idx < MAX_SLOT; idx++)
    {
        mInventory[idx] = NULL;
    }
    for (int idx = 0; idx < MAX_SLOT; idx++)
    {
        if (materiaSource.mInventory[idx] != NULL)
        {
            mInventory[idx] = materiaSource.mInventory[idx]->Clone();
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& materiaSource)
{
    std::cout << "MateriaSource assignation operator" << std::endl;
    if (this != &materiaSource)
    {
        for (int idx = 0; idx < MAX_SLOT; idx++)
        {
            delete mInventory[idx];
            mInventory[idx] = NULL;
        }
        for (int idx = 0; idx < MAX_SLOT; idx++)
        {
            if (materiaSource.mInventory[idx] != NULL)
            {
                mInventory[idx] = materiaSource.mInventory[idx]->Clone();
            }
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int idx = 0; idx < MAX_SLOT; idx++)
    {
        delete mInventory[idx];
        mInventory[idx] = NULL;
    }
    std::cout << "MateriaSource destructor" << std::endl;
}

void MateriaSource::LearnMateria(AMateria* materia)
{
    if (materia == NULL)
    {
        std::cerr << "Error: MateriaSource cannot learn a NULL materia" << std::endl;
        return ;
    }
    for (int idx = 0; idx < MAX_SLOT; idx++)
    {
        if (mInventory[idx] == NULL)
        {
            mInventory[idx] = materia;
            std::cout << "MateriaSource learned a new materia" << std::endl;
            return ;
        }
    }
    std::cerr << "Error: MateriaSource inventory is full" << std::endl;
}

AMateria* MateriaSource::CreateMateria(std::string const& type)
{
    for (int idx = 0; idx < MAX_SLOT; idx++)
    {
        if (mInventory[idx] != NULL && mInventory[idx]->GetType() == type)
        {
            std::cout << "MateriaSource found a materia of type " << type << std::endl;
            return (mInventory[idx]->Clone());
        }
    }
    std::cerr << "Error: MateriaSource cannot find a materia of type " << type << std::endl;
    return (NULL);
}
