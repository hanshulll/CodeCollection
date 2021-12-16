
const audio = document.getElementById('audio')
const play = document.querySelector('#playPause')
const topText = document.querySelector('#topText')
const title = document.querySelector('#title')
const author = document.querySelector('#sub-title')
const prev = document.querySelector('#prev')
const next = document.querySelector('#next')
const container = document.querySelector('#container')
const progressBar = document.querySelector('#progress-bar')
const progress = document.querySelector('#progress')
const heroImg = document.querySelector('#hero')
const back = document.getElementById('back')
const liked = document.getElementById('like')
const btnLike = document.getElementById('btnLike')
let totalDuration = document.getElementById('total')
let totalCurrent = document.getElementById('current')

const music = [
    {
        name: 'worst',
        fullName: 'At My Worst',
        author: 'Pink Sweats',
        hero: 'worst',
        likeImg: 'dislike',
        likeImage: 'dislike'
    },
    {
        name: 'tumMile',
        fullName: 'Tum Mile',
        author: 'Javed Ali',
        hero: 'tumMile',
        likeImg: false,
        likeImage: 'dislike'
    },
    {
        name: 'Sapno',
        fullName: 'Sapno Ki Rani',
        author: 'Kishore Kumar',
        hero: 'Sapno',
        likeImg: false,
        likeImage: 'dislike'
    },
    {
        name: 'Saibo',
        fullName: 'Saibo',
        author: 'Tochi Raina',
        hero: 'Saibo',
        likeImg: false,
        likeImage: 'dislike'
    },
    {
        name: 'mastMagan',
        fullName: 'Man Masta Magan',
        author: 'Arijit Singh',
        hero: 'mastMagan',
        likeImg: false,
        likeImage: 'dislike'
    },
    {
        name: 'brownMunde',
        fullName: 'Brown Munde',
        author: 'AP Dillion',
        hero: 'brownMunde',
        likeImg: false,
        likeImage: 'dislike'
    },
    {
        name: 'phelaNasa',
        fullName: 'Phela Nasha',
        author: 'Sadhana Sargam',
        hero: 'phelaNasa',
        likeImg: false,
        likeImage: 'dislike'
    },
    {
        name: 'punjabi',
        fullName: 'Punjabi Mashup',
        author: 'unknown',
        hero: 'punjabi',
        likeImg: false,
        likeImage: 'dislike'
    }
]

//event listner
prev.addEventListener('click', prevSong)
next.addEventListener('click', nextSong)
progressBar.addEventListener('click', setProgress)
audio.addEventListener('timeupdate', updateProgress)
back.addEventListener('click', prevSong)
btnLike.addEventListener('click', likeDislike)
// Song ends
audio.addEventListener('ended', nextSong);

//keep track of song
let songIndex = 0;

loadMusic(music[songIndex])

function loadMusic(song) {
    hero.src = `./img/${song.hero}.jpg`
    title.innerText = song.fullName;
    author.innerText = song.author;
    audio.src = `./music/${song.name}.mp3`

}

function loadHeart(heart) {
    liked.src = `./img/${heart.likeImage}.png`
}
function likeDislike() {
    music[songIndex].likeImg = !music[songIndex].likeImg
    // console.log(music[songIndex])
    if (music[songIndex].likeImg) {
        music[songIndex].likeImage = 'like'
    } else {
        music[songIndex].likeImage = 'dislike'
    }
    loadHeart(music[songIndex])
}

play.addEventListener('click', () => {
    const isPlaying = container.classList.contains('song')
    if (isPlaying) {
        pauseSong()
    } else {
        playSong()
    }
})

function playSong() {
    container.classList.add('song')
    document.querySelector('#onOff').src = './img/playing.png'
    topText.textContent = "Playing song..."
    audio.play()
}

function pauseSong() {
    container.classList.remove('song')
    document.querySelector('#onOff').src = './img/paused.png'
    topText.textContent = "Paused song..."
    audio.pause()
}

function prevSong() {
    songIndex--;
    if (songIndex < 0) {
        songIndex = music.length - 1;
    }
    loadMusic(music[songIndex])
    playSong()
}

function nextSong() {
    songIndex++;
    if (songIndex > music.length - 1) {
        songIndex = 0
    }
    loadMusic(music[songIndex])
    playSong()
}

// Update progress bar
function updateProgress(e) {
    const { duration, currentTime } = e.srcElement;
    const progressPercent = (currentTime / duration) * 100;
    progress.style.width = `${progressPercent}%`;

    //music duration update
    let minDuration = Math.floor(duration / 60)
    let secDuration = Math.floor(duration % 60)
    let totDuration = `${minDuration}:${secDuration}`
    if (duration) {
        totalDuration.textContent = `${totDuration}`;
    }

    //current duration update
    let minCurrent = Math.floor(currentTime / 60)
    let secCurrent = Math.floor(currentTime % 60)
    if (secCurrent < 10) {
        secCurrent = `0${secCurrent}`
    }
    let totCurrent = `${minCurrent}:${secCurrent}`
    totalCurrent.textContent = `${totCurrent}`;
}

// Set progress bar
function setProgress(e) {
    const width = this.clientWidth;
    const clickX = e.offsetX;
    const duration = audio.duration;
    console.log(duration)
    audio.currentTime = (clickX / width) * duration;
}


