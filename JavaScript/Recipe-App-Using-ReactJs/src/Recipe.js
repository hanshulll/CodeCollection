import React from 'react';


const Recipe = ({title,label, calories, image, ingredients}) => {
    return ( 
    <div className="recipe_b" key={title}>
        <h3>{label}</h3>
        <p><b>Calories: </b> {calories}</p>
        <img src={image} alt=""/>
        <h4>Ingredients: </h4>
       <ol>
        {
        ingredients.map(ingredient =>
            (<li>{ingredient.text}</li>))
        }
       </ol>
    </div>    
     );
}
 
export default Recipe;