const express=require("express");
const https=require("https");

const app=express();


app.get("/",function(req,res){

  const url= "https://api.openweathermap.org/data/2.5/weather?q=Dhanbad&appid=066c61b70fd357a35d98b775fc4f35de&units=metric"
  https.get(url,function(response)
  { 
      console.log(response.statusCode);
      response.on("data",function(data){
         const weatherdata=JSON.parse(data);
         const temp=weatherdata.main.temp
         const weatherdesc=weatherdata.weather[0].description;
         const icon=weatherdata.weather[0].icon;
         const imageURL="http://openweathermap.org/img/wn/"+icon+"@2x.png";
         res.write("<h2>The weather description in Dhanbad: "+weatherdesc+"</h2>");
         res.write("<h1>The temperature in Dhanbad is: "+temp+" degree Celsius</h1>");
         res.write("<img src="+imageURL+">");
         res.send();
      });
  })


});

app.listen(3000,function(){
    console.log("The server is running at port 3000");
});