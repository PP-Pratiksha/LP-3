// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Bank3{
    mapping ( address => uint ) balances;

    function deposite() public payable {
        balances[ msg.sender] = balances[msg.sender] + msg.value;
    }

    function withdraw( uint amount ) public{

        require( amount <= balances[msg.sender],"Insuffiecient balances");
        balances[msg.sender] = balances[msg.sender]-amount;
        payable (msg.sender).transfer(amount);
    }

    function checkbalance() public  view returns( uint ){
        return  balances[msg.sender];
    }
}