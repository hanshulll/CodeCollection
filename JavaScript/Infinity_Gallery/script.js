imageContainer11=document.getElementById("image-container11");
imageContainer12=document.getElementById("image-container12");
imageContainer13=document.getElementById("image-container13");
imageContainer14=document.getElementById("image-container14");


loader=document.getElementById("loader");
// let total=0;
var i=0;
let totalImages=0;
let imagesLoaded=0;
let ready=false;
let photosArray=[];
count=30;
apiKey="l1IR3IuUW1OZAtzu1YQhsEbhVW5ebiI0D9zm-hlfIvY";
url=`https://api.unsplash.com/photos/random?client_id=${apiKey}&count=${count}`;

function imageLoad(){
    imagesLoaded++;
    // total++;
    // console.log("number of images imagesLoaded",total)
    // console.log("image loaded",imagesLoaded);
    if(imagesLoaded===totalImages){
        ready=true;
        loader.hidden=true;
        // console.log("ready=",ready);
    }
}
function displayPhotos(photos){
    imagesLoaded=0;
    // console.log(photos);
    totalImages=photos.length;
    // console.log("total images=",totalImages);
    photos.forEach((photo)=>{
        //Creating the anchor tag element
        const item = document.createElement('a');
        item.setAttribute('href',photo.links.html);
        item.setAttribute('target', '_blank');
        // Creating the image tag element
        const img=document.createElement('img');
        img.setAttribute('src', photo.urls.regular);
        img.setAttribute('alt', photo.alt_description);
        img.setAttribute('title', photo.alt_description);
        img.addEventListener('load',imageLoad);
        item.appendChild(img);
        //3x3 format
        // mod=i%9;
        // switch(mod){
        //     case 0:
        //     case 1:
        //     case 2:imageContainer11.appendChild(item);
        //             i++;
        //             break;
        //     case 3:
        //     case 4:
        //     case 5:imageContainer12.appendChild(item);
        //             i++;
        //             break; 
        //     case 6:
        //     case 7:
        //     case 8:imageContainer13.appendChild(item);
        //             i++;
        //             break;
        //     default:imageContainer12.appendChild(item);
        // }
        mod=i%16;
        mod < 4 ? (imageContainer11.appendChild(item),i++) : 
        mod >= 4 && mod < 8 ? (imageContainer12.appendChild(item),i++) :
        mod >= 8 && mod < 12 ? (imageContainer13.appendChild(item),i++) :
        (imageContainer14.appendChild(item),i++);
    });
}
function getPhotos()
{
    fetch(url).then(res => res.json())
    .then(photosArray => displayPhotos(photosArray))
}
window.addEventListener('scroll',()=>{
    if(window.innerHeight+window.scrollY>=document.body.offsetHeight-1000 && ready){
        ready=false;
        getPhotos();
    }
});
//On load
getPhotos();