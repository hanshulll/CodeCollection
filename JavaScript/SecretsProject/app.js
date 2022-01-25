//Here LEVEL-1,LEVEL-2,LEVEL-3 AND LEVEL-4 security has been shown
require('dotenv').config();
const express=require('express');
const bodyParser=require('body-parser');
const ejs=require('ejs');
const mongoose=require('mongoose');
const validator=require('validator');
//const encrypt=require('mongoose-encryption');  USED IN LEVEL-2
//const md5=require('md5');              USED IN LEVEL-3
const bcrypt=require('bcrypt');      //USED IN LEVEL-4
const saltRounds = 10;
const app=express();

app.use(express.static("public"));
app.set('view engine', 'ejs');
app.use(bodyParser.urlencoded({extended: true}));

mongoose.connect("mongodb://localhost:27017/userDB", { useNewUrlParser: true })
.then(()=> console.log("Connection successful..."))
.catch((err)=>console.log(err));

const userSchema= new mongoose.Schema({
      email: {
          type: String, 
          required:true, 
          validate(value){
            if(!validator.isEmail(value))    //Npm Validator
            throw new Error("Email is invalid");
           }},
      password: {
          type: String, 
          required: true, 
      }
    
});

//Level-2
/*userSchema.plugin(encrypt, { secret: process.env.SECRET , encryptedFields: ['password']});*/
const User= new mongoose.model("User",userSchema);

//Level-3 (Hashing) see in the register route below in password

//Level-4 Salting and Hashing by bcrypt in register route below in password


app.get("/",function(req,res){
    res.render("home");
});
app.get("/login",function(req,res){
    res.render("login");
});
app.get("/register",function(req,res){
    res.render("register");
});

app.post("/register",function(req,res){

    bcrypt.hash(req.body.password, saltRounds, function(err, hash) {
        
    const newUser= new User({
        email: req.body.username,
        //password: req.body.password       LEVEL-2
        //password: md5(req.body.password)  Level-3
        password: hash
        });
    newUser.save(function(err){
        if(!err)
        res.render("secrets");
        else
        console.log(err);
     });  
    });

});
app.post("/login",function(req,res){
    const username=req.body.username;
    const password=req.body.password;       //   LEVEL-2 and LEVEL-4
   //const pass=md5(req.body.password);   LEVEL-3
   
    User.findOne({email: username},function(err,foundUser){
        if(err)
        console.log(err);
        else
        {
            if(foundUser){
                if(bcrypt.compareSync(password, foundUser.password)){
                    res.render("secrets");
                }
                else
                res.send("Invalid Credentials")
            }
            else{
                res.redirect("/login");            
            }
        }
    })
});
app.listen(3000,function(){
    console.log("The server is running at port 3000");
});