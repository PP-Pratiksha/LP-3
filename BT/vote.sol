//SPDX-License-Identifier: MIT 
pragma solidity ^0.8.0;
contract Voting {

    struct Candidate {
        uint id;
        string name;
        uint voteCount;
    }
    struct Voter {
        bool voted;
        uint vote;
    }
    address public owner;
    mapping(uint => Candidate) public candidates;
    mapping(address => Voter) public voters;
    uint public candidatesCount;
    uint public totalVotes;
    
    modifier onlyOwner() {
        require(msg.sender == owner, "Only owner can call this function");
    _;
    }

    constructor() {
        owner = msg.sender;
        addCandidate("Alice");
        addCandidate("Bob");
    }

    function addCandidate(string memory _name) public onlyOwner {
        candidatesCount++;
        candidates[candidatesCount] = Candidate(candidatesCount, _name, 0);
    }

    function vote(uint _candidateId) public {
        require(!voters[msg.sender].voted, "Already voted");
        require(_candidateId > 0 && _candidateId <= candidatesCount, "Invalid candidate");
        voters[msg.sender].voted = true;
        voters[msg.sender].vote = _candidateId;
        candidates[_candidateId].voteCount++;
        totalVotes++;
    }

    function getCandidate(uint _id) public view returns (string memory name, uint voteCount) {
        Candidate memory candidate = candidates[_id];
        return (candidate.name, candidate.voteCount);
    }
}
