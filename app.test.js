const mongoose = require('mongoose')
const registerProfile = require('../models/userProfile.models')
const loginProfile = require('../models/userProfile.models')
const checkProfile = require('../models/userProfile.models');

const url = "mongodb://127.0.0.1:27017/swifted_database";

beforeAll(async()=>{
    await mongoose.connect(url,
        {
            useNewUrlParser:true,
            useCreateIndex:true
        }
    )
})

afterAll(async()=>{
    await mongoose.connection.close();
})


describe("User Testing", ()=>{

    //Registration Testing
    it("User Registration Testing",()=>{
        const user = {
            firstname: "test9",
            lastname: "test9",
            username: "test9",
            email: "test9@gmail.com",
            phone: "9865412612",
            address: "test9",
            password: "123456",
            userType: "Admin"
        }
        return registerProfile.create(user)
        .then((register_ret) =>{
            expect(register_ret.username).toEqual("test9")
        })
    })

    // Login Testing
    it("User Login Testing", async() => {
       const data = {
           "username": "test9",
           "password": "123456"
       }
       return loginProfile.findOne({data});
       
    })

    // Check Profile Testing
    it ("Check User Profile Test", async() => {
        const status = await checkProfile.findById({"_id":Object("60e831fb8f3c4f1d482bc2c1")
    })
    return checkProfile.findOne({"_id":Object("60e831fb8f3c4f1d482bc2c1")})
    } )

    //Update Profile Testing
    it ("Update Profile Test", async() => {
        const status = await checkProfile.updateOne({"_id":Object("60e831fb8f3c4f1d482bc2c1")
    },
    {
        $set: {
            "phone": "98123456789",
            "address": "donetest"
        }
    
    })
    
        expect(status.ok).toBe(1)
    })

})

