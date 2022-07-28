class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x=0;
        int y=0;
        int dir=2;
        for(char ch:instructions){
            if(ch=='G'){
                if(dir==2) y++;
                else if(dir==-2) y--;
                else if(dir==1) x++;
                else x--;
            }
            else if(ch=='L'){
                if(dir==2) dir=-1;
                else if(dir==-2) dir=1;
                else if(dir==1) dir=2;
                else dir=-2;
            }
            else{
                if(dir==2) dir=1;
                else if(dir==-2) dir=-1;
                else if(dir==1) dir=-2;
                else dir=2;
            }
        }
        return (!x && !y) || (dir!=2);
    }
};