//box for each number
class box {
    public:
        int val = -1; //-1 when not solved
        int options[9] = {0}; //1 is available, 0 is not available
};