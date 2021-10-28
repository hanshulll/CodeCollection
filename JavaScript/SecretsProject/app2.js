//Using passport.js to add cookies and sessions
require('dotenv').config();
const express=require('express');
const bodyParser=require('body-parser');
const ejs=require('ejs');
const mongoose=require('mongoose');
const validator=require('validator');
const session = require('express-session');
const passport=require('passport');
const passportLocalMongoose=require('passport-local-mongoose');

const app=express();

app.use(express.static("public"));
app.set('view engine', 'ejs');
app.use(bodyParser.urlencoded({extended: true}));


app.use(session({
  secret: "My own little secret.",
  resave:false,
  saveUninitialized: false
}));
app.use(passport.initialize());
app.use(passport.session());

mongoose.connect("mongodb://localhost:27017/userDB", { useNewUrlParser: true })
.then(()=> console.log("Connection successful..."))
.catch((err)=>console.log(err));

const userSchema= new mongoose.Schema({
      username: {
          type: String,
          required:true,
          unique:true,
         validate(value){
            if(!validator.isEmail(value))    //Npm Validator
            throw new Error("Email is invalid");
           }},
      password: {
          type: String,
          unique:true
      }
    
});

userSchema.plugin(passportLocalMongoose);


const User= new mongoose.model("User",userSchema);



passport.use(User.createStrategy());
passport.serializeUser(User.serializeUser());
passport.deserializeUser(User.deserializeUser());

app.get("/",function(req,res){
    res.render("home");
});
app.get("/login",function(req,res){
    res.render("login");
});
app.get("/register",function(req,res){
    res.render("register");
});
app.get("/secrets",function(req,res){
    if(req.isAuthenticated()){
        res.render("secrets");
    }
    else
    res.redirect("/login");
});
app.get("/logout",function(req,res){
    req.logout();
    res.redirect("/");
});


app.post("/register",function(req,res){

    User.register({username: req.body.username},req.body.password,function(err,user){
        if(err)
        {
            console.log(err);
            res.redirect("/register");
        }
        else
        {
           passport.authenticate("local")(req,res,function(){
               res.redirect("/secrets");
           });
        }
    });

});
app.post("/login",function(req,res){
    const newUser=new User({
        username: req.body.username,
        password: req.body.password
    });
    req.login(newUser,function(err){
        if(err){
            console.log(err);
        }
        else
        {
            passport.authenticate("local")(req,res,function(){
               res.redirect("/secrets");
            });
        }
    });
});

app.listen(3000,function(){
    console.log("The server is running at port 3000");
});