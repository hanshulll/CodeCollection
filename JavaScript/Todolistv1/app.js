const express= require("express");
const bodyParser=require("body-parser");
const app=express();
const date=require(__dirname+"/date.js");

app.set('view engine', 'ejs');
var items=["Buy Food", "Cook Food","Eat Food"];
var workItems=[];
app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static("public"));
app.get("/",function(req,res) 
{
    let day=date.getDate();//Own model created and used
    res.render("list",{ListTitle: day,NewListItems: items});
});
app.post("/",function(req,res){
    let item =req.body.newItem;
    if(req.body.list === "work"){
      workItems.push(item);
      res.redirect("/work");
    }
    else
     {
         items.push(item);
         res.redirect("/");
     }
});

app.get("/work",function(req,res){
     res.render("list",{ListTitle: "Work List",NewListItems: workItems});
});

app.post("/work",function(req,res){
  let item=req.body.newItem;
  workItems.push(item);
  res.redirect("/work");
});

app.listen(3000,function() {
    console.log("Server started on port 3000");
});
