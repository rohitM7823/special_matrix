class Formulas{

protected:
    static inline int size(int n){
        return n*(n+1)/2;
    }

    static inline int row_major_lower(int i, int j){
        return (i*(i-1)/2)+(j-1);
    }

    static inline int col_major_lower(int n, int i, int j){
        return n*(j-1) - ((j-2)*(j-1)/2) + (i-j);
    }

    static inline int row_major_upper(int n, int i, int j){
        return n*(i-1) - ((i-2)*(i-1)/2) + (j-i);
    }

    static inline int col_major_upper(int i, int j){
        return (j*(j-1)/2)+(i-1);
    }
};

