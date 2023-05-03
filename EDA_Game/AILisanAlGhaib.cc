#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME LisanAlGhaib


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }

  /**
   * Types and attributes for your player can be defined here.
   */ 

    typedef vector<int> units;
    Pos GeneralPrevious[70][70];
    
    
    Dir caminito(int x,int y, int xo,int yo){
        Pos p;
        while(((x != xo)or(y != yo+1)) and ((x != xo)or(y != yo-1))and((y!=yo)or(x != xo+1))and((y!=yo)or(x != xo-1))){
            p=GeneralPrevious[x][y];
            x=p.i;
            y=p.j;
        }
        int dx= x-xo;
        int dy= y-yo;
        if( dx==0) {
           if (dy==-1)return LEFT;
           else return RIGHT;}
           else if(dy==0) {if (dx==1)return BOTTOM;}
           return TOP;

    }
    
    
    
    
    Dir first_half(int i, int j, CellType ctype) {

        int x,y;
        queue<Pos> q;
        q.push(Pos(i,j));
        bool checked[70][70]= { {false} };
        checked[i][j]=true;
        
        while (not q.empty()){

            x= q.front().i;
            y= q.front().j;
            Pos pcell(x,y);
            q.pop();
            
            if (x!=69 and x!=0 and y!=69 and y!=0){
        
                if (!checked[x+1][y]){
                    GeneralPrevious[x+1][y]= pcell;
                    checked[x+1][y]=true;
                  
                   if(ctype==CITY) {if (cell(x+1,y).type== ctype and (cell(x+1,y).city_id==-1 or city_owner(cell(x+1,y).city_id)!=me())) return caminito(x+1,y,i,j);
                        else{if(cell(x+1,y).type != ctype and cell(x+1,y).type!=WALL) q.push(Pos(x+1,y));}}
                    
                else if (ctype==PATH){if (cell(x+1,y).type== ctype and (cell(x+1,y).path_id==-1 or path_owner(cell(x+1,y).path_id)!=me())) return caminito(x+1,y,i,j);
                    else{if(cell(x+1,y).type != ctype and cell(x+1,y).type!=WALL) q.push(Pos(x+1,y));}}
                    
                else if (ctype==GRASS){if (cell(x+1,y).unit_id!=-1 and unit(cell(x+1,y).unit_id).player!=me() and unit(cell(x+1,y).unit_id).health<unit(cell(i,j).unit_id).health) return caminito(x+1,y,i,j);
                    else{if(cell(x+1,y).type!=WALL) q.push(Pos(x+1,y));}}
                }
                
                
                if (!checked[x-1][y]){
                    GeneralPrevious[x-1][y]= pcell;
                    checked[x-1][y]=true;
                    
                   if (ctype==CITY) {if (cell(x-1,y).type== ctype and (cell(x-1,y).city_id==-1 or city_owner(cell(x-1,y).city_id)!=me())) return caminito(x-1,y,i,j);
                        else{if(cell(x-1,y).type != ctype and cell(x-1,y).type!=WALL) q.push(Pos(x-1,y));}}
                    
                  else if (ctype==PATH) {if (cell(x-1,y).type== ctype and (cell(x-1,y).path_id==-1 or path_owner(cell(x-1,y).path_id)!=me())) return caminito(x-1,y,i,j);
                        else{if(cell(x-1,y).type != ctype and cell(x-1,y).type!=WALL) q.push(Pos(x-1,y));}}
                  
                  else if (ctype==GRASS) {if (cell(x-1,y).unit_id!=-1 and unit(cell(x-1,y).unit_id).player!=me() and unit(cell(x-1,y).unit_id).health<unit(cell(i,j).unit_id).health) return caminito(x-1,y,i,j);
                      else{if(cell(x-1,y).type!=WALL) q.push(Pos(x-1,y));}}
                }
            
                
                if (!checked[x][y+1]){
                    GeneralPrevious[x][y+1]= pcell;
                    checked[x][y+1]=true;
                    
                    if(ctype==CITY){if (cell(x,y+1).type == ctype and (cell(x,y+1).city_id==-1 or city_owner(cell(x,y+1).city_id)!=me())) return caminito(x,y+1,i,j);
                        else {if(cell(x,y+1).type != ctype and cell(x,y+1).type!=WALL) q.push(Pos(x,y+1));}}
                    
                    else if(ctype==PATH){if (cell(x,y+1).type == ctype and (cell(x,y+1).path_id==-1 or path_owner(cell(x,y+1).path_id)!=me())) return caminito(x,y+1,i,j);
                        else{if(cell(x,y+1).type != ctype and cell(x,y+1).type!=WALL) q.push(Pos(x,y+1));}}
                    
                    else if(ctype==GRASS){if (cell(x,y+1).unit_id!=-1 and unit(cell(x,y+1).unit_id).player!=me() and unit(cell(x,y+1).unit_id).health<unit(cell(i,j).unit_id).health) return caminito(x,y+1,i,j);
                        else{if(cell(x,y+1).type!=WALL) q.push(Pos(x,y+1));}}
                }
                
                
                if (!checked[x][y-1]){
                    GeneralPrevious[x][y-1]= pcell;
                    checked[x][y-1]=true;
                    if(ctype==CITY){if (cell(x,y-1).type== ctype and (cell(x,y-1).city_id==-1 or city_owner(cell(x,y-1).city_id)!=me())) return caminito(x,y-1,i,j);
                        else{if(cell(x,y-1).type != ctype and cell(x,y-1).type!=WALL) q.push(Pos(x,y-1));}}
                    
                    else if(ctype==PATH){if (cell(x,y-1).type== ctype and (cell(x,y-1).path_id==-1 or path_owner(cell(x,y-1).path_id)!=me())) return caminito(x,y-1,i,j);
                        else{if(cell(x,y-1).type != ctype and cell(x,y-1).type!=WALL) q.push(Pos(x,y-1));}}
                    
                    else if(ctype==GRASS){if (cell(x,y-1).unit_id!=-1 and unit(cell(x,y-1).unit_id).player!=me() and unit(cell(x,y-1).unit_id).health<unit(cell(i,j).unit_id).health) return caminito(x,y-1,i,j);
                        else{if(cell(x,y-1).type!=WALL) q.push(Pos(x,y-1));}}
                }
                
            }
        } return NONE;
    }

  /**
   * Play method, invoked once per each round.
   */
  virtual void play () {
      
      int mi, mj;
      
      units U = my_units(me()); // Get the id's of my units.
      int n = U.size();
      for (int i = 0; i < n; ++i) {
          int id= U[i];
          Unit u = unit(id);
          mi= u.pos.i;
          mj= u.pos.j;
          
          
          if (round()>=20 and i%3==0) move(id,first_half(mi,mj,GRASS));
          
          
          
          else if (cell(mi+1,mj).unit_id!=-1 and unit(cell(mi+1,mj).unit_id).player!=me() ){
              if( unit(cell(mi+1,mj).unit_id).health<=u.health)move(id,BOTTOM);
              else move(id,TOP);}
          
          else if (cell(mi-1,mj).unit_id!=-1 and unit(cell(mi-1,mj).unit_id).player!=me()  ){
              if(unit(cell(mi-1,mj).unit_id).health<=u.health)move(id,TOP);
              else move(id,BOTTOM);}
          
          else if (cell(mi,mj+1).unit_id!=-1 and unit(cell(mi,mj+1).unit_id).player!=me()  ){
              if(unit(cell(mi,mj+1).unit_id).health<=u.health)move(id,RIGHT);
              else move(id,LEFT);}
          
          else if (cell(mi,mj-1).unit_id!=-1 and unit(cell(mi,mj-1).unit_id).player!=me()  ){
              if(unit(cell(mi,mj-1).unit_id).health<=u.health)move(id,LEFT);
              else move(id,RIGHT);}
        
          
          
          else{ if (cell(u.pos).type==GRASS) {
              
           if (i%2==0)move(id,first_half(mi,mj,PATH));
          else move(id,first_half(mi,mj,CITY));}
          
          
          
          
        
          else if(cell(u.pos).type==CITY) {
              
              if (cell(mi,mj).city_id==me() and cell(mi+1,mj).unit_id==-1 and cell(mi-1,mj).unit_id==-1 and cell(mi,mj+1).unit_id==-1 and cell(mi,mj-1).unit_id==-1){
                  move(id,NONE);}
              
              
             else {move(id,first_half(mi,mj,PATH));}}
          
          
    
          
          else if(cell(u.pos).type==PATH) {
              
               if (cell(mi,mj).path_id==me() and cell(mi+1,mj).unit_id==-1 and cell(mi-1,mj).unit_id==-1 and cell(mi,mj+1).unit_id==-1 and cell(mi,mj-1).unit_id==-1) move(id,NONE);
              
              
              else move(id,first_half(mi,mj,CITY));}}

          
    }
      
      
  }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
