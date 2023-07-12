#ifndef TEMPLATES_TPP
# define TEMPLATES_TPP

template<typename VarType>
void swap(VarType& A, VarType& B)
{
    VarType C;
    
    C = A;
    A = B;
    B = C;
}

template<typename VarType>
VarType min(VarType A, VarType B)
{
    if (A < B)
        return(A);
    else
        return(B);
}

template<typename VarType>
VarType max(VarType A, VarType B)
{
    if (A <= B)
        return(B);
    else
        return(A);
}

#endif