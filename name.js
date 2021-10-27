const myfrinds = ["Harshal",
    "Nikhil",
    "Samidha",
    1998,
    "Kavi",
    "Rupesh",
    1999
];


for (let i = 0; i < myfrinds.length; i++) {
    if (typeof myfrinds[i] === 'string') continue;
    console.log(myfrinds[i]);
