/*
GAME RULES:

- The game has 2 players, playing in rounds
- In each turn, a player rolls a dice as many times as he whishes. Each result get added to his ROUND score
- BUT, if the player rolls a 1, all his ROUND score gets lost. After that, it's the next player's turn
- The player can choose to 'Hold', which means that his ROUND score gets added to his GLBAL score. After that, it's the next player's turn
- The first player to reach 100 points on GLOBAL score wins the game

*/


var player,dice,activePlayer,scoreCurrent,scorePlayer,result;

 init();


 document.querySelector(".dice").style.display="none"



document.querySelector(".btn-roll").addEventListener("click",function(){

    if(result){

        document.querySelector(".dice").style.display="block"

        var rollDice=Math.floor(Math.random()*6);
        var imgSrc=dice[rollDice]
         document.querySelector(".dice").src=imgSrc;
        
      
          if((rollDice+1)!==1){
            
              var diceNumber=rollDice+1;
              scoreCurrent += diceNumber;
              document.querySelector("#current-"+activePlayer).textContent=scoreCurrent;
          }
          else{
        
            DRY();
          }
         

    }

   

});


document.querySelector(".btn-hold").addEventListener("click",function(){


    if(result){

            
        player[activePlayer] +=scoreCurrent;
        document.querySelector("#score-"+activePlayer).textContent=player[activePlayer];

        if(player[activePlayer]>=100){

            document.querySelector(".dice").style.display="none";

            document.querySelector(".player-0-panel").classList.remove("active");
            document.querySelector(".player-1-panel").classList.remove("active");

            document.querySelector(".player-"+activePlayer+"-panel").classList.add("winner");
            document.querySelector("#name-"+activePlayer).textContent=" Winner! "

            result=false;

        }
        else{
            DRY();
        }

    }
        
       

})


function DRY(){

    scoreCurrent=0;
    document.querySelector(".dice").style.display="none"
    activePlayer===0?activePlayer=1:activePlayer=0;

    document.querySelector("#current-0").textContent=0;
    document.querySelector("#current-1").textContent=0;

    document.querySelector(".player-0-panel").classList.toggle("active");
    document.querySelector(".player-1-panel").classList.toggle("active");
}



document.querySelector(".btn-new").addEventListener("click",function(){

    init();

})


function init(){

    player=[0,0]
    result=true;
    activePlayer=0,scoreCurrent=0,scorePlayer=0;
    dice=["dice-1.png","dice-2.png","dice-3.png","dice-4.png","dice-5.png","dice-6.png",]

    document.querySelector("#current-0").textContent=0;
    document.querySelector("#current-1").textContent=0;
    document.querySelector("#score-0").textContent=0;
    document.querySelector("#score-1").textContent=0;

    document.querySelector(".player-0-panel").classList.remove("active");
    document.querySelector(".player-1-panel").classList.remove("active");

    document.querySelector(".player-0-panel").classList.remove("winner");

    document.querySelector(".player-0-panel").classList.add("active");


    document.querySelector("#name-0").textContent=" Player 1 "
    document.querySelector("#name-1").textContent=" Player 2 "


}
