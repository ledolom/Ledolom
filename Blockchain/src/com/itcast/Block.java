package com.itcast;

import java.util.Date;

public class Block {
    //当前区块的hash
    public String hash;
    //前一个区块的hash,以此实现链
    public String previousHash;
    //当前区块的数据
    private String data;
    //时间戳
    private long timeStamp;

    private int nonce;

    public Block(String hash,String previousHash,String data){
        this.hash=hash;
        this.previousHash=previousHash;
        this.data=data;
    }

    public Block(String data,String previousHash ) {
        this.previousHash = previousHash;
        this.data = data;
        this.timeStamp=new Date().getTime();
        this.hash=calculateHash();
    }

    public String calculateHash() {
        String calculateHash = StringUtil.applySha256(
                previousHash+
                        Long.toString(timeStamp)+
                        Integer.toString(nonce)+
                        data);
        return calculateHash;
    }

    public void mineBlock(int difficulty){
        String target=new String(new char[difficulty]).replace('\0','0');
        while (!hash.substring(0,difficulty).equals(target)){
            nonce++;
            hash=calculateHash();
        }
    }

}
