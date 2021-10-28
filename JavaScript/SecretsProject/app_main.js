//LEVEL-6 OAUTH 2.0 and Implement Sign in from Google
require('dotenv').config();
const express=require('express');
const bodyParser=require('body-parser');
const ejs=require('ejs');
const mongoose=require('mongoose');
const validator=require('validator');
const session = require('express-session');
const passport=require('passport');
const passportLocalMongoose=require('passport-local-mongoose');
const GoogleStrategy = require('passport-google-oauth20').Strategy;
const FacebookStrategy = require("passport-facebook").Strategy;
const findOrCreate = require('mongoose-findorcreate')
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
          unique:true,
         validate(value){
            if(!validator.isEmail(value))    //Npm Validator
            throw new Error("Email is invalid");
           }},
      password: {
          type: String,
          unique:true
      },
      googleId:{
        type:String
      },
      facebookId:
    {
    type: String,
    },
      secret: [{type: String}]
    
});

userSchema.plugin(passportLocalMongoose);
userSchema.plugin(findOrCreate);

const User= new mongoose.model("User",userSchema);



passport.use(User.createStrategy());
passport.serializeUser(function(user, done) {
    done(null, user.id);
  });
  
  passport.deserializeUser(function(id, done) {
    User.findById(id, function(err, user) {
      done(err, user);
    });
  });
//GOOGLE AUTHENTICATION
passport.use(new GoogleStrategy({
    clientID: process.env.CLIENT_ID,
    clientSecret: process.env.CLIENT_SECRET,
    callbackURL: "http://localhost:3000/auth/google/secrets",

  },
  function(accessToken, refreshToken, profile, cb) {
      console.log(profile);
    User.findOrCreate({ googleId: profile.id }, function (err, user) {
      return cb(err, user);
    });
  }
));
//FACEBOOK AUTHENTICATION
passport.use(new FacebookStrategy(
    {
        clientID: process.env.FACEBOOK_CLIENT_ID,
        clientSecret: process.env.FACEBOOK_CLIENT_SECRET,  
        callbackURL: "https://localhost:3000/auth/facebook/secrets",
        profileFields: ['id', 'displayName', 'photos', 'email'],
    },
    
    function(accessToken, refreshToken, profile, cb)
      {
    User.findOrCreate({ facebookId: profile.id }, function (err, user)
    {
          return cb(err, user);
    
    });
    }
));
app.get("/",function(req,res){
    res.render("home");
});
//GOOGLE AUTHENTICATION
app.get('/auth/google',
  passport.authenticate('google', { scope: ["profile"] }));

app.get('/auth/google/secrets', 
  passport.authenticate('google', { failureRedirect: '/login' }),
  function(req, res) {
    // Successful authentication, redirect to secrets page.
    res.redirect('/secrets');
  });

//FACEBOOK AUTHENTICATION
app.get("/auth/facebook",

  passport.authenticate("facebook",  ));

app.get("/auth/facebook/secrets",
  passport.authenticate("facebook", { failureRedirect: "/login" }),
  function(req, res)
  {
    res.redirect("/secrets");
  });


app.get("/login",function(req,res){
    res.render("login");
});
app.get("/register",function(req,res){
    res.render("register");
});
app.get("/secrets",function(req,res){
  User.find({"secret":{$ne:null}}, function(err,foundUsers){
      if(err){ 
          console.log(err);
      }
      else{
          res.render("secrets",{usersWithSecrets: foundUsers});
      }
  });
});
app.get("/submit",function(req,res){
    if(req.isAuthenticated()){
        res.render("submit");
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
app.post("/submit",function(req,res){
     const submittedsecret=req.body.secret; 
     console.log(req.user.id);

     User.findById(req.user.id,function(err,foundUser){
      if(err){
          console.log(err);
      }
      else{
        
             foundUser.secret=submittedsecret;
             foundUser.save(function(){
                 res.redirect("/secrets");
             });
         
      }
     });
});
app.listen(3000,function(){
    console.log("The server is running at port 3000");
});