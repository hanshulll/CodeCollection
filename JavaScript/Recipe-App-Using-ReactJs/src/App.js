import './App.css';
import React, {useEffect, useState} from "react";
import Recipe from './Recipe.js';





const  App= ()=> {
  const APP_ID = '85edd1ff';
  const APP_KEY='2ee187ac914af73f72f9277c23458862';
  const [recipe,setRecipe] =useState(null);
  const [search, setSeaarch]=useState('');
  const [query, setQuery]=useState('dish');

  const searchVal = (e) => {
    setSeaarch(e.target.value);
  }
  
  const searchClick = (e) =>{
    e.preventDefault();
    setQuery(search);
  }
  useEffect (()=>
  {
    getData();
  // eslint-disable-next-line react-hooks/exhaustive-deps
  },[query])

  const getData = async ()=>{
    const response = await fetch(`https://api.edamam.com/search?q=${query}&app_id=${APP_ID}&app_key=${APP_KEY}`);
    const data =await response.json();
    setRecipe(data.hits);
    console.log(recipe);
  }

  return (
  
    <div className="App">
      <h1>Search For Healthy And Tasty Recipes</h1>
      <form className="search-bar" onSubmit={(e)=>searchClick(e)}>
        <input className="search-text" type="text" value={search} onChange={(e)=>searchVal(e)}/>
        <button className="search-button" type="submit" >Search</button>
      </form>
      <div className="recipe_blog">
        {recipe && recipe.map(recipes=>(
            <Recipe  
            title = {recipes.recipe.label}
            label={recipes.recipe.label} 
            calories={recipes.recipe.calories} 
            image ={recipes.recipe.image}
            ingredients = {recipes.recipe.ingredients}>
            </Recipe>
          ))}
      </div>
      
    </div>
  );
}

export default App;
