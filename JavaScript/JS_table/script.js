let data = {
  "givenData": [
      {
      "id": 1,
      "name": "Bruce Wayne",
      "subject1": 80,
      "subject2": 45,
      "subject3":90
      },
      {
      "id": 2,
      "name": "Diana",
      "subject1": 56,
      "subject2": 74,
      "subject3":78
      },
      {
      "id": 3,
      "name": "Clark Kent",
      "subject1": 67,
      "subject2": 78,
      "subject3":90
      },
      {
      "id": 4,
      "name": "Barry Allen",
      "subject1": 89,
      "subject2": 35,
      "subject3":64
      },
      {
      "id": 5,
      "name": "Arthur Curry",
      "subject1": 76,
      "subject2": 65,
      "subject3":100
      },
      {
      "id": 6,
      "name": "Victor Stone",
      "subject1": 99,
      "subject2": 87,
      "subject3":64
      }
]
}
data=data.givenData.filter((element)=>{return element});
function createTable(data){
  var table=document.getElementById('dataTable');
  data.forEach((element)=>{
    element.maxMarks= Math.max(element.subject1, element.subject2, element.subject3);
    var row = `<tr>
                  <td class="name">${element.name}</td>
                  <td>${element.id}</td>
                  <td>${element.subject1}</td>
                  <td>${element.subject2}</td>
                  <td>${element.subject3}</td>
                  <td>${element.maxMarks}</td>
               </tr>`
    table.innerHTML += row;
    //console.log("added");
  })
}
createTable(data);